#include<stdio.h>
int copy(char f[],char t[]);
main()
{
char from[100],to[100];
int i,j=0,c;
for(i=0;i<100&&(c=getchar())!=EOF&&c!='\n';++i){
from[i]=c;
}
copy(from,to);
for(j=copy(from,to);j>=0;--j){
	putchar(to[j]);
}
printf("\n");
}
int copy(char f[],char t[])
{
int k=0;
while((t[k]=f[k])!='\0')
++k;
return k;
}
