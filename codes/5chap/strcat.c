#include<stdio.h>
char *mystrcat(char *s1,char *s2);
main()
{
	char str[100]="abh",st[100]="ilash";
	mystrcat(str,st);
	puts(str);
}
char *mystrcat(char *s1,char *s2)
{
	int i=0;
	while(*s1!='\0'){
		*s1++;
		++i;
	}
	while(*s2!='\0'){
		*s1++=*s2++;
	}
	return s1;
}
