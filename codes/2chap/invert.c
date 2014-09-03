#include<stdio.h>
unsigned invert(unsigned x,int p,int n)
{
return  x^(~(~0<<n)<<(p+1-n));
}
main()
{
unsigned int x;
int p,n;
printf("x,p,n");
scanf("%u%d%d",&x,&p,&n);
printf("inverted=%u",invert(x,p,n));
}
