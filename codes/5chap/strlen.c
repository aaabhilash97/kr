#include<stdio.h>
int mystrlen(char *s);
main()
{
	char str[100];
	scanf("%s",str);
	printf("s=%d",mystrlen(str));
}
int mystrlen(char *s)
{
	int i=0;
	while(*s!='\0'){
		i++;
		s++;
	}
	if(*s==' ')
	return i;
}
