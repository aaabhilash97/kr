#include<stdio.h>
main()
{
int c,ch=0;
printf("Enter the string");
c=getchar();
while(c!=EOF){
++ch;
c=getchar();
if(c=='\n'){
  printf("%d",ch);
     break;
}
}
}
