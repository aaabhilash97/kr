#include<stdio.h>
#include<string.h>
void reverse(char *p,char *q);
main()
{	char pas[100];
	char cop[100];
	scanf("%s",cop);
int i=0;
	reverse(cop,pas);
//puts(cop);
puts(pas);
}
void reverse(char *p,char *q)
{
	int i=0;
	while(*p++!='\0')
		i++;
	*p--;
	while(i>0){
	*q++=*--p;
	--i;
	}
	*q='\0';
		
}
