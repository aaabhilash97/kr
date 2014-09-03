#include <stdio.h>
#include <getopt.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>

#include <bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

#include <string.h>
#include <signal.h>

int sock = -1;
int hcdfile_fd = -1;
int bdaddr_flag = 0;
int enable_lpm = 0;
int debug = 0;

unsigned char buffer[1024];

unsigned char hci_reset[] = { 0x01, 0x03, 0x0c, 0x00 };

unsigned char hci_download_minidriver[] = { 0x01, 0x2e, 0xfc, 0x00 };

unsigned char hci_write_bd_addr[] = { 0x01, 0x01, 0xfc, 0x06,
					0x00, 0x00, 0x00, 0x00,
					0x00, 0x00, 0x00 };

#define HCIT_TYPE_COMMAND 1

int parse_patchram(char *optarg)
{
	char *p;

	p = strrchr(optarg, '.');
	if (!p) {
		fprintf(stderr, "file %s not an HCD file\n", optarg);
		exit(3);
	}

	p;

	if (strcasecmp("hcd", p) != 0) {
		fprintf(stderr, "file %s not an HCD file\n", optarg);
		exit(4);
	}

	hcdfile_fd = open(optarg, O_RDONLY);
	if (hcdfile_fd == -1) {
		fprintf(stderr, "file %s could not be opened, error %d\n",
								optarg, errno);
		exit(5);
	}

	return 0;
}

int parse_bdaddr(char *optarg)
{
	int bd_addr[6];
	int i;

	sscanf(optarg, "%02x%02x%02x%02x%02x%02x",
		&bd_addr[0], &bd_addr[1], &bd_addr[2],
		&bd_addr[3], &bd_addr[4], &bd_addr[5]);

	for (i = 0; i < 6; ++i)
		hci_write_bd_addr[4 + i] = bd_addr[i];

	bdaddr_flag = 1;

	return 0;
}

int parse_cmd_line(int argc, char **argv)
{
	int c;
	int digit_optind = 0;
	int dev_id;

	typedef int (*PFI)();

	PFI parse_param[] = { parse_patchram, parse_bdaddr };

	while (1) {
		int this_option_optind = optind ? optind : 1;
		int option_index = 0;

		static struct option long_options[] = {
						{"patchram", 1, 0, 0},
						{"bd_addr", 1, 0, 0},
						{0, 0, 0, 0}
		};

		c = getopt_long_only(argc, argv, "d",
				long_options, &option_index);

		if (c == -1)
			break;

		switch (c) {
		case 0:
			printf("option %s", long_options[option_index].name);

			if (optarg)
				printf(" with arg %s", optarg);

			printf("\n");

			(*parse_param[option_index])(optarg);
			break;

		case 'd':
			debug = 1;
			break;

		case '?':
			/* nobreak */
		default:
			printf("Usage %s:\n", argv[0]);
			printf("\t<-d> to print a debug log\n");
			printf("\t<--patchram patchram_file>\n");
			printf("\t<--bd_addr bd_address>\n");
			printf("\tbluez_device_name\n");
			break;
		}
	}

	if (optind < argc) {
		printf("%s ", argv[optind]);

		dev_id = hci_devid(argv[optind]);
		if (dev_id == -1) {
			fprintf(stderr, "device %s could not be found\n",
								argv[optind]);
			exit(1);
		}

		printf("devid %d\n", dev_id);

		sock = hci_open_dev(dev_id);
		if (sock == -1) {
			fprintf(stderr, "device %s could not be found\n",
								argv[optind]);
			exit(2);
		}

		printf("sock %d\n", sock);
	}

	printf("\n");

	return 0;
}

void init_hci()
{
	struct hci_filter flt;

	hci_filter_clear(&flt);
	hci_filter_set_ptype(HCI_EVENT_PKT, &flt);
	hci_filter_all_events(&flt);

	setsockopt(sock, SOL_HCI, HCI_FILTER, &flt, sizeof(flt));
}

void dump(unsigned char *out, int len)
{
	int i;

	for (i = 0; i < len; i) {
		if (i && !(i % 16))
			fprintf(stderr, "\n");

		fprintf(stderr, "%02x ", out[i]);
	}
	fprintf(stderr, "\n");
}

void read_event(int fd, unsigned char *buffer)
{
	int i = 0;
	/* int len = 3;*/
	int len = 260;
	int count;

/*
	while ((count = read(sock, &buffer[i], ++len)) < len) {
		i = count;
		len -= count;
	}

	i = count;
	len = buffer[2];

	while ((count = read(sock, &buffer[i], ++len)) >  len) {
		i = count;
		len -= count;
	}
*/
	count = read(sock, &buffer[i], 260);

	if (debug) {
		count = i;

		fprintf(stderr, "received %d\n", count);
		dump(buffer, count);
	}
}

void hci_send_cmd_func(unsigned char *buf, int len)
{
	uint8_t type;
	hci_command_hdr hc;
	struct iovec iv[3];
	int ivn;

	if (debug) {
		fprintf(stderr, "writing\n");
		dump(buf, len);
	}

	if (buf[0] == HCIT_TYPE_COMMAND) {
		type = HCI_COMMAND_PKT;
	} else {
		while (write(sock, buf, len) < 0) {
			if (errno == EAGAIN || errno == EINTR)
				continue;

			return;
		}
		return;
	}

	hc.opcode = buf[1] | (buf[2] << 8);
	hc.plen = len - 4;

	iv[0].iov_base = &type;
	iv[0].iov_len = 1;
	iv[1].iov_base = &hc;
	iv[1].iov_len = HCI_COMMAND_HDR_SIZE;
	ivn = 2;

	if (len - 4) {
		iv[2].iov_base = &buf[4];
		iv[2].iov_len = len - 4;
		ivn = 3;
	}

	while (writev(sock, iv, ivn) < 0) {
		if (errno == EAGAIN || errno == EINTR)
			continue;

		return;
	}

}

void expired(int sig)
{
	hci_send_cmd_func(hci_reset, sizeof(hci_reset));
	alarm(4);
}

void proc_reset()
{
	signal(SIGALRM, expired);

	hci_send_cmd_func(hci_reset, sizeof(hci_reset));

	alarm(4);

	read_event(sock, buffer);

	alarm(0);
}

void proc_patchram()
{
	int len;

	hci_send_cmd_func(hci_download_minidriver,
				sizeof(hci_download_minidriver));

	read_event(sock, buffer);

	/* read(sock, &buffer[0], 2); */

	sleep(1);

	while (read(hcdfile_fd, &buffer[1], 3)) {
		buffer[0] = 0x01;

		len = buffer[3];

		read(hcdfile_fd, &buffer[4], len);

		hci_send_cmd_func(buffer, len  4);

		read_event(sock, buffer);
	}

	proc_reset();
}

void proc_bdaddr()
{
	hci_send_cmd_func(hci_write_bd_addr, sizeof(hci_write_bd_addr));

	read_event(sock, buffer);
}

int main(int argc, char **argv)
{
	parse_cmd_line(argc, argv);

	if (sock < 0)
		exit(1);

	init_hci();

	proc_reset();

	if (hcdfile_fd > 0)
		proc_patchram();

	if (bdaddr_flag)
		proc_bdaddr();

	return 0;
}

