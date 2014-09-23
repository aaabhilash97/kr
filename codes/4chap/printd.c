#include <stdio.h>
void printd(int n);
main()

{
int n=-1234;
printd(n);
}
void printd(int n)
{
printf("q");
//printf("ddsds");
if (n < 0) {
putchar('-');
n = -n;
}
if (n / 10){
printf("a");
printd(n / 10);}
printf("end");
putchar(n % 10 + '0');

}
