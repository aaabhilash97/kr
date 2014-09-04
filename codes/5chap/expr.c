#include<stdio.h>
#include<stdlib.h>
void push(double f);
double pop(void);
main(int argc,char *argv[])
{
	 int c,i=1;
	 double d,op1,op2;
		while(i<argc){
			switch(*argv[i]){
				case '-':
					op1=pop();
					push(pop() - op1);					
					++i;
					break;
				case '/':
					op1=pop();
					op2=pop();
					push(op2/op1);					
					++i;
					break;	
				case 'x':
					push(pop() * pop());					
					++i;
					break;
				case '+':
					push(pop() + pop());					
					++i;
					break;
				default:
					push(atof(argv[i]));
					++i;
					break;
			}			
	}printf("result=%f",pop());
	
}
#define MV 100
int store[MV];
int sp=0;
void push(double d)
{
	store[sp++]=d;
}
double pop(void)
{
printf("%d",sp);
	return store[--sp];
}	
