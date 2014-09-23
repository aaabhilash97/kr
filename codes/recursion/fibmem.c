#include<stdio.h>
#include<stdlib.h>
int s[9999999];
int fib(int n)
{
	if(n<2) return n;
	else{
		if(s[n-1]==0)
			s[n-1]=fib(n-1);
		if(s[n-2]==0)
			s[n-2]=fib(n-2);
		return s[n-1]+s[n-2];
	}
}
main(int argc,char *argv[])
{
	printf("%d",fib((int)atof(argv[1])));;
}
