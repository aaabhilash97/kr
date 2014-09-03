#include<stdio.h>
main()
{
int c;
int w=0;
c=getchar();
while((c=getchar())!=EOF){
  if(c==' '|| c=='\n'|| c=='n'){
    ++w;
    if(c=='\n'){
      printf("%d\n",w);
            break;
}
}
}
}
