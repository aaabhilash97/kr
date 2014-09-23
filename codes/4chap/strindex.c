#include<stdio.h>
int strindex(char s[],char t[])
{
	int i=0,c,k=0;
	while(s[i]!='\0'){
		c=s[i]; 
		++i;
	}
	while(t[k]!='\0'){
		if(t[k]==c)
			return k+1;
		++k;
	}
	return -1;
}
main()
{
	char t[]="qwertyutrdhhdew";
	char s[]="qwqxcxdfdfda";
	printf("%d",strindex(s,t));
}	
