#include<stdio.h>
#include<string.h>
int getch(void);
void ungets(char s[]);
main()
{
int i,c;
char str[]="1234";
//scanf("enter%s",str);
ungets(str);
while((c=getch())!=EOF)
	putchar(c);
}


#define M 100
char buf[M]="wr";
int bufp=0;
int getch(void)
{
	return (bufp>0)?buf[--bufp]:getchar();
}
void ungetch(int c)
{
	buf[bufp++]=c;
}
void ungets(char s[])
{
	int m,j=strlen(s),i,k=j,q=strlen(buf),w=j;
	if(q>0){
		for(m=q-1;m>=0;m--){
			buf[w]=buf[m];
			w++;
			bufp++;
		}
	}
	i=0;
	for(i=0;i<k;i++){
		buf[i]=s[--j];
		bufp++;
	}
}
