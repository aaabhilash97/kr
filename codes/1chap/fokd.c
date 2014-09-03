#include<stdio.h>
int fold(void);
main()
{
char a[100];
int c,i=0,l=0,j,e=1,ws;
while((c=getchar())!=EOF){
	if(c==' '||c=='\t'||c=='\n'){
	 if(e==0){
	e=1;
	   if(c==' '){
		ws=i;
		if(l==40){
		a[i]=10;
		l=0;
	     }
		else if(l<40||l==40){
		    a[i]=32;
		}
		}
	   if(c=='\n'){

		for(j=0;j<i;++j){
			putchar(a[j]);
		}
		}
		++i;
		++l;
}
	}
else if(e==0||e==1){
if(l==40){
a[ws]=10;
l=0;
}
a[i]=c;
++i;
++l;
e=0;
}
}
}
