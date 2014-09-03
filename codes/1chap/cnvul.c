#include<stdio.h>
int lower(char c)
{
return c>='A'&&c<='Z' ? c+'a'-'A':c;
}
main()
{
int c,i,k;
char s[100];
for(i=0;i<100&&(c=getchar())!=EOF&&c!='\n';++i){
	s[i]=c;
}
printf("\n");
for(k=0;k<i;++k){
	putchar(lower(s[k]));
    }
printf("\n");
}
