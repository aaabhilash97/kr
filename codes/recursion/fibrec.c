#include<stdio.h>
#include<stdlib.h>
int fib(int n)
{
	if(n<2) return n;
	else return fib(n-1)+fib(n-2);
}
main(int argc,char *argv[])
{
	printf("%d",fib((int)atof(argv[1])));;
}
