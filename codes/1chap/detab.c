#include<stdio.h>
void  detab(void);
char line[100];
main()
{
detab();
}
void detab(void)
{
extern char line[];
int i=0,e=0,c,j;
for(j=0;j<=100;++j){line[j]='\0';}
while((c=getchar())!=EOF&&c!='\0'){

   if(c==' '||c=='\t'||c=='\n'){
	if(e==1){
	   e=0;
	   if(c=='\t'){
		line[i]=32;
		}
	   if(c==' '){
		line[i]=32;
		}
	   if(c=='\n'){
		for(j=0;j<=i;++j){
		  putchar(line[j]);
		   }
	     }
	  }
	++i;
      }
else if(e==0||e==1){
	line[i]=c;
	++i;
e=1;
      } 
}
}
