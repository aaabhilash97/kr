#include<stdio.h>
#include<string.h>
void getlines(char *p);
main()
{
char a[100];
getlines(a);
printf("%s",a);
}
void getlines(char *p)
{
	int c;
	for(c=getchar();c!='\n';c=getchar()){
//printf("erer");
		*p++=c;
//c=getchar();
	}
	if(c=='\n')
		*p++=c;
	*p='\0';
//	return 1;
}
