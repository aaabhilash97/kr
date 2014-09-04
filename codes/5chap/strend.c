#include<stdio.h>
int mystrend(char *s,char *p);
main()
{
	char a[122]="abhilash",b[433]="lash";
	printf("%d",mystrend(a,b));
}

int mystrend(char *s,char *p)
{
	int sl=0,pl=0;
	while(*s!='\0'){
		++sl;
		*++s;
	}
	while(*p!='\0'){
		*++p;
		++pl;
	}
	while(pl>0){
		if(*--p==*--s)
			--pl;
		else
			return 0;
	}
	return 1;
}
