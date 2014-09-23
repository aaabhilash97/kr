#include<stdio.h>
#include<stdlib.h>
int fib(int n)
{
	if(n<2) return n;
	int a=0,b=1,pos=2;
	while(pos<=n){
	 	int temp=b;
		b=a+b;
		a=temp;
		pos++;
	}
	return b;
}
main(int argc ,char *argv[])
{
	printf("%d",fib((int)(atof(argv[1]))));
}
