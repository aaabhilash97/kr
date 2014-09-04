#include<stdio.h>
#include<string.h>
void itoa(int n,char s[]);
main()
{
	int n=18372923,i=0;
	char s[100];
	itoa(n,s);
	while(s[i]!='\0'){
		printf("%d",s[i]);
		++i;
	}
}
int i=0;
void itoa(int n,char s[])
{
//	printf("%d\n",n);

	if(n<0){
		s[i++]='-';
		n=-n;
	}
	if(n/10)
		itoa(n/10,s);
	printf("\n%d\t%d\n",s[i++]=n%10,i);
	s[i]='\0';
	return;
}
