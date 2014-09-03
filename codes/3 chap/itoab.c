#include<stdio.h>
#include<string.h>
void itoa(int n,char s[],int b)
{
	char c;
	int i=0, sign,z=0;
	if ((sign = n) < 0)
	n = -n;
	do {
	s[i++] = n % 10 + '0'; /* get next digit */
	} while ((n /= 10) > 0);

	for(z=i+1;b>0;--b,++z){
		s[z]=' ';
	}

	if (sign < 0)
	s[z++] = '-';
	s[i] = '\0';

	while(b<z){
	c=s[b];
	s[b]=s[z];
	s[z]=c;
	++b;--z;
	}	
}
main()
{
 	int n,b,i,k;
 	char s[100];
 	for(i=0;i<100;++i){
 		s[i]='\0';
 	}
 	scanf("%d%d",&n,&b);
 	itoa(n,s,b);
 	for(k=0;k<100;++k){
 		printf("%c",s[k]);
	}
}
