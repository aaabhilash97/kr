#include<stdio.h>
#include<string.h>
int itoa(int *i,char *s);
main()
{
	char str[100];
	int a;
	scanf("%d",&a);
	itoa(&a,str);
	puts(str);
}
int itoa(int *n,char *s)
{	
	
	char *copy=s;
	int len=0;
	do{
		*s++=*n%10+'0';
len++;
//printf("%c\t%d\t%d\n",*s,*n,len);
	*n/=10;
	}while(*n>0);
	*s='\0';
	char *cop=s-len;
	char buf;
	while(cop<s){
		--s;
		buf=*s;
		*s=*cop;
		*cop=buf;
		++cop;
	}
}
