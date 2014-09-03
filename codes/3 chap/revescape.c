#include<stdio.h>
int revescape(char p[],char q[])
{
	int i;
	i=0;
	while(i<20){
		switch(p[i]){
			case '\\':
                                if(p[i+1]=='t')
                                {
                                        q[i+1]='\t';
                                        i+=2;
                                }
                                if(p[i+1]=='n')
                                {
                                        q[i+1]='\n';
                                        i+=2;
                                }
                                        break;
				default :
				q[i]=p[i];
				++i;
				break;
		   }
	 }
}
main()
{
char s[20],t[20];
int c,i,l,k;
for(l=0;l<20;++l){
	s[l]=t[l]='\0';
    }
for(i=0;i<=20&&(c=getchar())!=EOF;++i){
	s[i]=c;
}
revescape(s,t);
for(k=0;k<20;++k){
        putchar(t[k]);
}
}
