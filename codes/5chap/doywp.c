#include<stdio.h>
void mod(int *year,int *yd,int *month,int *day);
int doy(int *year,int *month,int *day);
main()
{	int year,month,day,yd;
	scanf("%d%d%d",&year,&month,&day);
	printf("%d\n",(yd=doy(&year,&month,&day)));
	mod(&year,&yd,&month,&day);
	printf("\n%d\t%d",month,day);
		
}
static char daytab[2][13]={
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
int doy(int *year,int *month,int *day)
{
	int i,leap;
	leap=(*year%4==0)?1:0;
	for(i=1;i<*month;i++)
		*day+=daytab[leap][i];
	return *day;	
}
void mod(int *year,int *yd,int *month,int *day)
{
printf("%d\t%d",*year,*yd);
	int i,leap;
	leap=(*year%4==0)?1:0;
	for(i=1;*yd>daytab[leap][i];i++)
		*yd-=daytab[leap][i];
	*day=*yd;	
	*month=i;
}		
