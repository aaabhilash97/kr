#include<stdio.h>
#include<string.h>
char *mystrcat(char *s1,char *s2,int n);
main()
{
	char str[100]="aaa",st[100]="ttt";
	mystrcat(str,st,3);
	puts(str);
	printf("%d",strncmp(str,st,2));
}
char *mystrcat(char *s1,char *s2,int n)
{
	while(n>0){
		*s1++=*s2++;
		--n;
	}
	return s1;
}
