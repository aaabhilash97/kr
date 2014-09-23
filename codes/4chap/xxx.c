#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int getop( double s[]);

main()
{
	double s[100];
	int type,i=0;
	while((type=getop(s))!=EOF||type!='\n'){
		if(type==0)
		printf("%f\n",s[i]);	
	else
		putchar(type);
}
}
void ungetch(int);
int getch(void);
int getop(double s[])
{
	int i=0,j,pow=1,c;
	double val;
	while((c=getch())==' '||c=='\t'||c=='\n')
		;
	while(!isdigit(c)&&c!='.')
		return c;
	if(isdigit(c)||c=='.'){
		for(val=0.0;isdigit(c);++j){
			val=val*10.0+(c-'0');
			c=getch();
		}
		if(c=='.'){
			c=getch();
//printf("sds");
			for(pow=1;isdigit(c);++j){
				val=val*10+(c-'0');
				pow=pow*10;
				c=getch();
			}
		
		}
		s[i]=val/pow;
//	printf("%f\n",s[i]);
	}
	if(c!=EOF){
		ungetch(c);
	}	
	return 0;
	
		
}
#define n 100
char buf[100];
int bufp=0;
int getch(void)
{ //printf("%d",buf[bufp]);

	return (bufp>0)? buf[--bufp]:getchar();
}
void ungetch(int k)
{
	buf[bufp++]=k;

}	
