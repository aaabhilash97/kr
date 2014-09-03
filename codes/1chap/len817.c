#include<stdio.h>
int c,j=0,i=0,e=0;
char s[100];
main()
{
while((c=getchar())!=EOF){
	if(c==' '||c=='\t'||c=='\n')
	{
		s[i]=c;
		++i;
		if(i>8&&c=='\n'){
		for(j=0;j<=i;j++)
		putchar(s[j]);
		}
	 }
 else if(e==0|| e==1){
	s[i]=c;
	++i;
}
}
}
