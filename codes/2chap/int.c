#include<stdio.h>
main()
{
signed char ch;
int n,c;
long int b=0;
short int a=0;
printf("range of what");
scanf("%d",&n);
if(n==1){
while(a>=0){
a=a+1;
b=a;
if(b>0){c=b;}
}
printf("positive limit%d\n",c);
a=0;
while(a<=0){
a=a-1;
b=a;
if(b<0){c=b;}
}
printf("negative imit=%d\n",c);

}
if(n==2){
while(ch>=0){
ch=ch+1;
b=ch;
if(b>0){c=b;}
}
printf("positive limit=%d\n",c);
ch=0;
while(ch<=0){
ch=ch-1;
b=ch;
if(b<0){c=b;}
}
printf("negative imit=%d\n",c);

}

}
