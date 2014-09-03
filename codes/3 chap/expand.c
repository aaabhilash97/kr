#include<stdio.h>
#include<string.h>
#include<ctype.h>
double expand(char s[],long t[])
{
	int i=0,j=0,c;
	long k=0,p=0,o=0;
	while((c=s[i])!='\0'){
	     	switch(s[i]){
		case '-':
			if(isdigit(s[i-1])&&isdigit(s[i+1])||isupper(s[i-1])&&isupper(s[i+1])||islower(s[i-1])&&islower(s[i+1])){
				c=s[i-1]+1;
				while(c<s[i+1]){
					t[j]=c;
					++c;++j;
				}
		  	}
			
			else if(++j){
				t[i]=s[i];
}
++i;
	           	break;
		default:
			t[j]=s[i];
   	        	++i;
         		++j;
			break;
	       }
	}
}

main()
{
int c,m,j,q;
char s[10000];
long t[10000];
for(q=0;q<100;++q){
	s[q]=t[q]='\0';
}
for(j=0;j<100&&(c=getchar())!=EOF&&c!='\n';++j){
	s[j]=c;
}
/*for(j=0;j<100;++j){
scanf("%s",&s[j]);
}*/
expand(s,t);
for(m=0;m<100;++m){
	putchar(t[m]);
}
printf("\n");
}
