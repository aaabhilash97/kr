#include<stdio.h>
#include <ctype.h>
#include<string.h>
/* atof: convert string s to double */
double atof(char s[])
{
	double val, power;
	int i,exp,sign;
	for(i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i])||isalpha(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	val=sign * val / power;
	if(s[i]=='e'||s[i]=='E')
		sign=(s[i++]=='-')?-1:1;
	++i;
putchar(s[i]);
	for(exp=0;isdigit(s[i]);++i)
		exp=10*exp+(s[i]-'0');
printf("%d\t%d\n",sign,exp);
	if(sign==1)
		while(exp-->0){
			val*=10;
		}
	else
		while(exp-->0){
			val/=10;
		}
	return val;
}
main()
{
char s[]="2.1e+4";
//scanf("%s",&s[]);
printf("%f",atof(s));
}
