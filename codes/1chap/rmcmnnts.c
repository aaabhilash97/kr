#include<stdio.h>
main()
{
char a[100];
int b=0,c,i=0,j=0,l,q=0,k;
for(i=0;i<100&&(c=getchar())!=EOF;++i){
a[i]=c;
	if(a[i]==42&&a[i-1]==47&&j==0){
	   j=1;
	   q=1;
	   a[i]=a[i-1]='\0';
	   b=i+1;
	}
	if(q==1){

	if(a[i]==47&&a[i-1]==42&&j==1){
	   j=0;
	   q=0;
	   for(l=b;l<=i;++l){
		a[l]='\0';
	   }
	}}
	if(a[i]==10){
	   for(k=0;k<i;++k){
	        putchar(a[k]);
	    }
	}
}
}
