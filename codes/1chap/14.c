#include<stdio.h>
main()
{
int ws=0,c,e=0,i=0,ch=0,f,d,a=0;
char p[10];
for(i=0;i<=10;++i){
    p[i]=0;
   }
while((c=getchar())!=EOF){
     if(c==' '||c=='\n'||c=='\t')
	{
	 ++ws;
	 if(c=='\n')
	    {
	     for(d=0;d<i;++d){

ch=1;
		for(f=d+1;f<=i;++f){
		if(p[f]!='\0'){
		    if(p[d]==p[f])
			{
			  ++ch;
			  p[f]='\0';
			}
		  }
		}
		if(p[d]!=0){

			putchar(p[d]);
	     		printf("\t%d",ch);
			for(a=0;a<ch;++a){
			   printf("|");
			}
printf("\n");
	   	}
}
	   }
	}
	else if(e==1 || e==0){
		p[i]=c;
		++i;
	     }
}
}
