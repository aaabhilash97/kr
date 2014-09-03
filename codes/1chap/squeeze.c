#include<stdio.h>
int squeeze(char s1[],char s2[]);
main()
{
char a[100],b[100];
squeeze(a,b);
}

int squeeze(char s1[],char s2[])
{
	int c,d,i,j,l,k,m,n=0,a;
	for(m=0;m<=100;++m){
	    s1[m]=s2[m]='\0';
	}
	printf("entr fst string");
	for(i=0;i<100&&(c=getchar())!=EOF&&c!='\n';++i){
		s1[i]=c;
//		putchar(s1[i]);
	}
                printf("\n");
	printf("2nd string");
        for(j=0;j<100&&(d=getchar())!=EOF&&d!='\n';++j){
                s2[j]=d;
//		putchar(s2[j]);
        }
        for(k=0;k<=i;++k){
		for(l=0;l<=j;++l){
			if(s1[k]==s2[l]){
			  s2[l]=s1[k];
			  s1[k]='\0';
			}
		}
	}
	for(i=0;i<k;++i){
                putchar(s1[i]);
	}
printf("\n");
}
