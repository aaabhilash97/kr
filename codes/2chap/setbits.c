#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
return (x & ~(~0 << p+1)<<(p + 1 - n)) | ((y & ~(~0 << n)) << (p + 1 - n));
}
main()
{
unsigned i=1,j=2;
int m=2,n=2;
printf("%u",setbits(i,m,n,j));
}
