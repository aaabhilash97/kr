#include<stdio.h>
main()
{
int i=0,c;
char s[100];
loop:
c=getchar();
if(c!='\n'){
   s[i]=c;
	putchar(s[i]);
   ++i;

   goto loop;
  }
}
