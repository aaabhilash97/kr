#include<stdio.h>
main()
{
int e=1,c,ch=0,i=0;
while((c=getchar())!=EOF){
if(c==' '|| c=='\n'|| c=='\t'){
if(e=1){
e=0;
printf("\t\t");
for(i=1;i<=ch;++i){
printf("|");
}
printf("\t%d",ch);
printf("\n");
}
ch=0;
}
else if(e==0 ||e==1){
++ch;
e=1;
putchar(c);}
}}
