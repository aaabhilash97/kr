#include<stdio.h>
#include<math.h>
int htoi(char s[]);
int power(int i);
main()
{
char h[100];
htoi(h);
printf("%d",h[0]);
}

int htoi(char h[])
{
	int t=0,p,i=0,c,d,q,k,r,e=1,f,x=16,l=7;
	int s[100];
	for(r=0;r<100;++r){
	   s[r]='\0';
	}
	for(i=0;i<100&&(c=getchar())!=EOF&&c!='\n';++i){
//printf("%d",c);
	   if(c==65||c==66||c==67||c==68||c==69||c==70){
              h[i]=c-55;
//printf("%d",h[i]);

            }
	   if(c==97||c==98||c==99||c==100||c==101||c==102){
	      h[i]=c-87;
//printf("%d",h[i]);

	    }
	    if(c=='0'||c=='1'||c==48||c==49||c==50||c==51||c==52||c==53||c==54||c==55||c==56||c=='9'){
		h[i]=c-'0';
//printf("%d",h[i]);
	     }
	}
	q=i-1;
	for(k=0;k<i;++k){
//	    printf("%d\t%d\n",q,h[k]);
	    e=power(q);
	    p=h[k]*e;
s[k]=p;
//printf("%d\t%d\n",s[k],k);
	    --q;
	}
printf("decimel=%d\n",s[0]+s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]);
}
int power(int i)
{
int d,e=1;
for(d=i;d>0;--d)
	e=e*16;

return e;
}
