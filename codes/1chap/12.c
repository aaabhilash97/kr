#include<stdio.h>
main()
{
int c,e=1;
int w=0;
printf("type words...\n");
while((c=getchar())!=EOF){

   if(c==' '|| c=='\n'|| c=='n'){ 
     if(e==1){
      e=0;
      printf("\n");
}
}


   else if(e==1||e==0){
       e=1;
       putchar(c);
}
}
}

