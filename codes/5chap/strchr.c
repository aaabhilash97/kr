#include<stdio.h>
char mystrchr(char *s1,char *s2);
main()
{
	char str1[100];
	char str2[100];
	scanf("%s",str1);
	scanf("%s",str2);
	printf("%d",mystrchr(str1,str2));
}

char mystrchr(char *s1,char *s2)
{
	char *b=s2;
	char c;
	int i=0,j=-1;
	while(*s2!='\0'){
		if(*s2!=*s1){
			s2=b;
			j=-1;
		}
		if(*s2==*s1){
			*s2++;
			j++;
		}
		*s1++;
		++i;
	}
	if(j!=0){
		return i-j;}
	else
		return 0;
}
