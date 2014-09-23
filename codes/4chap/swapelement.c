#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int getop( double s[]);
void push(double b);
double pop(void);
void swap(void);
void clear(void);
main()
{
	double s[1];
	double b,op;
	int op1,op2;
	int type,i=0;
	char n;
	while((type=getop(s))!=EOF){
b=s[i];
//printf("%f",b);
		switch(type){
			
			case 0:
			push(b);
//printf("%f",s);
				break;
			case '+':
				push(pop()+pop());
				break;
			case '*': 
                                push(pop()*pop());
                                break;
			case '/': 
				op=pop();
                                push(pop()/op);
                                break;
			case '-': 
				op=pop();
                                push(pop()-op);
                                break;
			case '%': 
				op1=pop();
				op2=pop();
				op=op2%op1;
//printf("%d",op1);
                                push(op);
                                break;
			case '\n':
				swap();
				printf("\nSUM=%f\n",pop());
				printf("clear satck?");
				scanf("%c",&n);
				if(n='y')
					clear();
				else
					;
				break;
			default:
				break;
		}
	}
	return 0;
}


#define M 100
int sp=0;
double valu[M];
double c;
void push(double b)
{
	if(sp<M){
		valu[sp++]=b;//printf("%d\t%f\n",sp-1,valu[sp-1]);
	}
	else
		printf("overflow");
}

double pop(void)
{
	if(sp>0){
		return valu[--sp];
	}
	else{
 		printf("empty");
		return 0.0;
	}
}
void swap(void)
{
	c=valu[sp];
	valu[sp]=valu[sp-1];
	valu[sp-1]=c;
	printf("%f\t%f",valu[sp],valu[sp-1]);
}
void clear(void)
{
	for(sp=0;sp<100;sp++)
		valu[sp]='\0';
}
void ungetch(int);
int getch(void);
int getop(double k[])
{
	int i=0,j,pow=1,c,sign=1;
	double val;
	while((c=getch())==' '||c=='\t')
		;
	while(!isdigit(c)&&c!='.'&&c!='-')
		return c;
	if(c=='-'){
		c=getch();
		sign=(isdigit(c))?-1:1;
//printf("%d",sign);
	
	if(sign==1)
		return '-';
	}
	if(isdigit(c)||c=='.'){
		for(val=0.0;isdigit(c);++j){
			val=val*10.0+(c-'0');
			c=getch();
		}
		if(c=='.'){
			c=getch();
//printf("sds");
			for(pow=1;isdigit(c);++j){
				val=val*10+(c-'0');
				pow=pow*10;
				c=getch();
			}
		
		}
		k[i]=sign*val/pow;
//printf("%f",k[i]);
	}
	if(c!=EOF){
		ungetch(c);
	}	
	return 0;
	
		
}

#define n 100
char buf[100];
int bufp=0;
int getch(void)
{ //printf("%d",buf[bufp]);

	return (bufp>0)? buf[--bufp]:getchar();
}

void ungetch(int k)
{
	buf[bufp++]=k;

}	

