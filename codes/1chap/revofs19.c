#include<stdio.h>
void rev(char a[]);
main()
{
char from[100];
int i,c;
for(i=0;i<100&&(c=getchar())!=EOF&&c!='\n';++i){
from[i]=c;
}
rev(from);
}
void rev(char a[])
{
int i=0,j;
while(a[i]!='\0'){
++i;
}
for(j=i;j>=0;--j){
putchar(a[j]);
}
}
