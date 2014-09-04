#include<stdio.h>
#include<ctype.h>
#include<string.h>
main()
{
	int array[100],getint(int *pn),n;
	for(n=0;n<100&&getint(&array[n])!=EOF;++n){
		printf("pn1=%d\t%d",array[n],n);
	}
}
int getch(void);
int s;
void unget(int c);
int getch(void);
void ungetch(int);
int getint(int *pn)
{
	int c, sign;
	while (isspace(c = getch()))
		;
	while(!isdigit(c) && c != EOF && c != '+' && c != '-') {
			c=getch();
		
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-'){
		c = getch();
		while(isalpha(c)||isspace(c)){
			c=getch();
		}
	}
	for (*pn =0; isdigit(c)||islower(c); c = getch()){
		if(islower(c))
			c='0';
		*pn = 10 * *pn + (c - '0');
	}
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}
int buf[100];
int bufp=0;
int getch(void)
{
	return (bufp>0)?buf[--bufp]:getchar();
}
void ungetch(int c)
{
	buf[bufp++]=c;
}
