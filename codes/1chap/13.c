#include<stdio.h>
main()
{
int c,i=0,w=0,ch=0,j=0,e=1;
char x[10],z[10],y[10];
for(i=0;i<=10;++i){
	x[i]=0;
	y[i]=0;
	z[i]=0;
	}
while((c=getchar())!=EOF){
	if(c==' '||c=='\t'||c=='\n'){
		ch=0;
		++w;
		if(e==1){
			e=0;
			if(c=='\n'){
				for(j=0;j<=10;++j){
					printf("%c\t",x[j]);
					}
					printf("\n");
				for(j=0;j<=10;++j){
                                        printf("%c\t",y[j]);
                                        }
					printf("\n");
				for(j=0;j<=10;++j){
                                        printf("%c\t",z[j]);
                                        }
					printf("\n");

				}
			}	
		}
	else if(e==1||e==0){
		e=1;               
		if(ch==0){
			x[w]='_';
			}
		if(ch==1){ 
                        y[w]='_';
                        }
		if(ch==2){ 
                        z[w]='_';
                        }
		++ch;
		}

}}
