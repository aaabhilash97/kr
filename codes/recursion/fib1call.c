#include<stdio.h>
int a=0,pos=1,b=1;
int fib(int n)
{

	if(n<2) return n;
	else {
		int temp=b;
		b=a+b;
		a=temp;
		pos++;
	}
	if(pos!=n)
		fib(n);
	return b;
}		
main()
{
	int n;
	scanf("%d",&n);
	printf("%d",fib(n));
}
