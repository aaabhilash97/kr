#include<stdio.h>
#include<string.h>
void reverse(char s[]);
main()
{
char s[100];
scanf("%s",s);
reverse(s);
printf("%s\n",s);
}
int i=0,j,k=1;
void reverse(char s[])
{
	if(k==1)
	{
		j=strlen(s)-1;
		k=0;
	}
	char c=s[i];
	s[i]=s[j];
	s[j]=c;
	++i;--j;
	if(i<j)
	reverse(s);
	return;
}
