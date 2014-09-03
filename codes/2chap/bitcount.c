#include<stdio.h>
int bitcount(unsigned x)
{
int b;
for (b = 0; x != 0; x &=x-1){
printf("%u\t%d\n",x,b);
	b++;}
return b;
}
main()
{
unsigned x;
printf("enter");
scanf("%u",&x);
printf("%d\t%u",bitcount(x),x);
}
