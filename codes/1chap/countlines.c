#include<stdio.h>
main()
{
int c,lin=0;
while((c=getchar())!=EOF){
    if(c=='\n'){
     ++lin;
printf("%d\n",lin);
}
}
}
