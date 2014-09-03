#include<stdio.h>
#define abs(x) ((x)<0 ? -(x) :(x))
/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
int i=0, sign,c,j,k;
//if ((sign = n) < 0)
sign=n;
i = 0;
do {
s[i++] =abs( n % 10) + '0';
//printf("%c\t\t%d\t%d\n",s[i],i,n);
} while ((n /= 10) != 0);
if (sign < 0)
s[i++] = '-';
s[i] = '\0';
//printf("%c\t%d%d\n",s[i],n,i);
//reverse(s);
j=0;
k=i;
while(j<k){
c=s[j];
s[j]=s[k];
s[k]=c;
--k;++j;
}

}
main()
{
char s[100];
int c,i;
int n;
scanf("%d",&n);
for(i=0;i<100;++i){
s[i]='\0';
}
itoa(n,s);
for(i=0;i<100;++i){
printf("%c",s[i]);
}
}
