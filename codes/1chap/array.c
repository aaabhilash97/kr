#include<stdio.h>
main()
{
int ch=0,i,j,c,a[10],ws=0;
for(i=0;i<10;++i){
  a[i]=0;}
i=0;
while((c=getchar())!=EOF){
     if(c>='0' && c<='9' && c!='\n'){
       a[i]=c-'0';
       ++i;
}
     else if(c==' '||c=='\t'){
      ++ws;
      }
else if(c=='\n'){
printf("ch=%d\n",ch);
          printf("ws=%d\n",ws);
printf("numbers");
            for(j=0;j<=9;++j){
              printf("\n%d\n",a[j]);}
     }
else{
++ch;
}
}
}
