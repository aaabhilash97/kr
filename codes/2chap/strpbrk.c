#include<stdio.h>
int str(char s1[],char s2[]);
main()
{
char a[100],b[100];
printf("%d\n",str(a,b));
}

int str(char s1[],char s2[])
{
	int c,d,i,j,l,k,m,n,x=-1;
	for(n=0;n<=100;++n){
	    s1[n]=s2[n]='\0';
	}
	printf("enter string 1=\n");
	for(i=0;i<100&&(c=getchar())!=EOF&&c!='\n';++i){
		s1[i]=c;
	}
                printf("\n");
	printf("enter string 2\n");
        for(j=0;j<100&&(d=getchar())!=EOF&&d!='\n';++j){
                s2[j]=d;
        }

        for(k=0;k<=i;++k){
		for(l=0;l<=j;++l){
			if(s1[k]==s2[l]){
			 if(s1[k]!='\0'){
			    x=0;
			    return x; 
  			  }
			    putchar(s1[k]);
			    for(m=0;m<100;++m){
				 if(s1[k]==s2[m]){s2[m]='\0';}
			    }
			}

		}
	}
/*	for(i=0;i<k;++i){*/
//		putchar(s1[i]);
//	}
return x;
//if(x==-1){
//printf("%d\n",x);
//}
}
