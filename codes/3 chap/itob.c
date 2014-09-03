#include<stdio.h>
int itob(int n,char s[],int b)
{
	int i=0,c,r,d=0,h;
	if(n<b){
		s[i]=n;
	}
	while((n/b)>0){
		s[i++]=(n%b);
//printf("%d",s[i]);
		n=n/b;
		if(n<b){
		  s[i]=n%b;
		}
	}
h=i;
	while(d<i){
		c=s[d];
		s[d]=s[i];
		s[i]=c;
		--i;++d;
	}
return h;
}

main()
{
int n,b,k,v;
char s[100];
for(v=0;v<100;++v){
	s[v]='\0';
}
scanf("%d%d",&n,&b);
for(k=0;k<=itob(n,s,b);++k){
	printf("%d",s[k]);
}
}
