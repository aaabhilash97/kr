#include<stdio.h>
#include<ctype.h>
#include<string.h>
int getfloat(float *pn);
main()
{
	float array[100];
	int n;
	for(n=0;n<100&&getfloat(&array[n])!='\n';n++)
		printf("\t%f",array[n]);
}
int getch(void);
void ungetch(int c);
int getfloat(float *pn)
{
	int c,sign=1,ex=1;
	c=getch();
	while(isspace(c)||c=='\t'||c=='\n')
		if(c=='\n')
			return c;
		else 
			c=getch();
	while(!isdigit(c)&&c!='-'&&c!='+')
		c=getch();
        if(c=='-'||c=='+')
	{
		sign=(c=='-')?-1:1;
		c=getch();
	}
	for(*pn=0.0;isdigit(c);c=getch()){
		*pn=*pn*10+(c-'0');
	}
	if(c=='.')
	{c=getch();
	//	c=getch();
		for(ex=1;isdigit(c);c=getch()){
			*pn=*pn*10+(c-'0');
			ex=ex*10;
		}
	}
	*pn=*pn*sign/ex;
	if(c!=EOF){
		ungetch(c);
	}
	return 0;
}

int buf[100],bufp=0;
int getch(void)
{
	return (bufp>0)?buf[--bufp]:getchar();
}
void ungetch(int c)
{
	buf[bufp++]=c;
}
