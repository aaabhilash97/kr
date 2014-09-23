#include<stdio.h>
int escape(char s[],char t[])
{
	int i=0;
	while(i<100){
	switch(t[i]){
	case '\t':
	    s[i]='\\';
	    s[i+1]='t';
	    i=i+2;
	    break;
	case '\n':
	     s[i]='\\';
	     s[i+1]='n';
	     i=i+2;
	     break;
	default:
	      s[i]=t[i];
		++i;
		break;
}
}
}
main()
{
int i,c,j,k;
char e[100];
char d[100];
for(j=0;j<100;++j){
	e[j]=d[j]='\0';
}
for(i=0;i<100&&(c=getchar())!=EOF;++i){
	d[i]=c;
	}
escape(e,d);
for(k=0;k<100;++k){
        putchar(e[k]);
        }
printf("\n");

}
