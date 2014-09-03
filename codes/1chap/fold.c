#include<stdio.h>
int fold(void);
main()
{
char a[100];
int c,i=0,l=0,j,e=1;
while((c=getchar())!=EOF){
	if(c==' '||c=='\t'||c=='\n'){
	 if(e==0){
	e=1;
	   if(c==' '){
		if(l>10){
		a[i]=10;
		l=0;
	     }
		else if(l<10||l==10){
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
a[i]=c;
++i;
++l;
e=0;
}
}
}
