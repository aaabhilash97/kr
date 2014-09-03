#include<stdio.h>
int setbit(char x[100],int p,int n,char y[100]);
main()
{
int p,n;
char x[100],y[100];
setbit(x,p,n,y);
}
int setbit(char x[100],int p,int n,char y[100])
{
 	int c,i,j,d,l;
	for(j=0;j<=100;++j){
            y[j]=x[j]='\0';
        }
        printf("enter string 1=\n");
        for(i=0;i<100&&(c=getchar())!=EOF&&c!='\n';++i){
                x[i]=c;
        }
                printf("\n");
        printf("enter string 2\n");
        for(j=0;j<100&&(d=getchar())!=EOF&&d!='\n';++j){
                y[j]=d;
        }
	printf("p&n");
	scanf("%d%d",&p,&n);
	while(n>0){
	x[p-1]=y[j-(n)];
	++p;
	--n;
	}
        for(l=0;l<=i;++l){
            putchar(x[l]);
        }
printf("\n");

}
