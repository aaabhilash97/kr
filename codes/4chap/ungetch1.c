#include<stdio.h>
#include<string.h>
int getch(void);

void ungetch(char s);
main()
{
int i,c;
char s='f';
//scanf("enter%s",str);
ungetch(s);
loop:
if((c=getch())!='\n'){
	putchar(c);
	goto loop;}
if((c=getch())==EOF){printf("hj");
	ungetch(s);
	
putchar(getch());}
}


#define M 100
char buf='\0';
int getch(void)
{
	if(buf!='\0'){
		char g=buf;
		buf='\0';
		return g;}
	else 
		return getchar();
}
void ungetch(char c)
{
	buf=c;
}
