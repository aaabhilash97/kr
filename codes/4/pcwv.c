#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int getop( double s[]);
void push(double b);
double pop(void);
void swap(void);
void clear(void);
double save(void);
main()
{
	double s[1],z[26];
	int flag[26];
	double a;
	double b,op;
	int op1,op2;
	int type,i=0,j;
	int n;
	for(j=0;j<26;++j)
		flag[j]='\0';
	while((type=getop(s))!=EOF){
if(type=='~'){loop: printf("exiting");break;}
b=s[i];
if(type>='a'&&type<='z'){
	if(flag[type-'a']!=1){
		z[type-'a']=save();
		flag[type-'a']=1;
		printf("%f",z[type-'a']);
	}
	else 
		push(z[type-'a']);
}
		switch(type){
			
			case 0:
			push(b);
//printf("%f",s);
				break;
			case '+':
				push(pop()+pop());
				break;
			case 's':
				op1=pop();
                                op=sin(op1);
				push(op);
                                break;
                        case 'c':
                                op1=pop();
                                op=cos(op1);
                                push(op);
                                break;
                        case 't':
                                op1=pop();
                                op=tan(op1);
                                push(op);
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
		//		if(n==1){goto loop;break;}
				printf("\nSUM=%f\n",pop());
				swap();
				printf("clear satck?");
				scanf("%d",&n);
				if(n==1){
					clear();
					type='~';
goto loop;
					break;
				}
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
		valu[sp++]=b;printf("%d\t%f\n",sp-1,valu[sp-1]);
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
double save(void)
{
	return valu[sp-1];
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

