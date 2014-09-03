#include<stdio.h>
main()
{
int b,c;
char  a=0;
while(a>=0){
++a;
b=a;
if(b>0){c=b;}
}
printf("%d\n",c);
a=0;
while(a<=0){
--a;
b=a;
if(b<0){c=b;}
}
printf("%d",c);

}
