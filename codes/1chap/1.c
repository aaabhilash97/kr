#include<stdio.h>
int c,i=0,j=0,e=1;
char a[10];
main()
{
while((c=getchar())!=EOF){
	if(c==' '||c=='\t'||c=='\n'){

		if(c==' '){
			if(e==1){
		   a[i]=32;
		   ++i;
		   e=0;
			}
		}
		if(c=='\t'){
		  }

	    
		if(c=='\n'){
		  for(j=0;j<=i;++j){
		  putchar(a[j]);

	          }  
		}
	     
	   }
	else if(e==0||e==1){
		e=1;
		a[i]=c;
		++i;
		}
}}

