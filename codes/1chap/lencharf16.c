#include<stdio.h>
#define mx 1000
int lenline(char line[],int ml);
main()
{
int wq,k;
char lem[mx];
printf("%d\t\n",lenline(lem,k));
return 0;
}

int lenline(char line[],int l)
{
int i,c,r;
for(i=0;i<l-1&&(c=getchar())!=EOF&&c!='\n';++i)
	r=c;
	return i;

}
