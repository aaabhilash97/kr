#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (a>b)?a:b
#define square(x) x*x
#undef getchar
#define dprint(expr) printf("%g",expr)
#define paste(front,back) printf("%s",front ## back)
#define swap(t,x,y) 	{t _z; _z=y; y=x; x=_z;}
main()
{
char s='f',c='e',sc[100]="abhilash";
	paste(s,c);
	swap(int,s,c);
	printf("%c",s);


}
