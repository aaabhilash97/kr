#include<stdio.h>
int strlen(char s[]);
main()
{
char s[5]={'w','w','w','e','s'};
printf("%d",strlen(s));
}
int strlen(char s[])
{
int i=0;
while (s[i] != '\0')
++i;
return i;
}
