#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key))
struct key {
char *word1;
int count;
} keytab[] = {
"auto", 0,
"break", 0,
"case", 0,
"char", 0,
"const", 0,
"continue", 0,
"default", 0,
"getch",0,
"return",0,
"switch",0,
"ungetch",0,
"unsigned", 0,
"void", 0,
"volatile", 0,
"while", 0
};
int getword(char *, int);
int binsearch(char *, struct key *, int);
/* count C keywords */
main()
{
int n;
char word[MAXWORD];
//loop:
	while (getword(word, MAXWORD) != 0){
		if (isalpha(word[0]))
			if ((n = binsearch(word, keytab, NKEYS)) >= 0){
				keytab[n].count++;
				///printf("no=%d word=%s\n",keytab[n].count, keytab[n].word1);
			}
	}
	printf("\n");
	for (n = 0; n < NKEYS; n++){
		if (keytab[n].count > 0)
			printf("%s-%d\n",keytab[n].word1,keytab[n].count);
	}
	//goto loop;
}
/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		if ((cond = strcmp(word, tab[mid].word1)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch())){
		if (c=='\n'){
			return 0;
		}
	;}
	
	if (isalpha(c)){
		*w++ = c;
	}
	if (!isalpha(c)) {
		if(c=='/'){
			if((c=getch())=='*'){
					while((c=getch())!='*')
						;
					if((c=getch())=='/'){
						if((c=getch())=='\n'){
							return 1;}
					}
			}
		}
	

		if(c=='"'){
			while((c=getch())!='"')
				;
		if((c=getch())=='\n')
			return 1;
		}
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())&&*w!='_') 
		{
			if(*w=='\n'){
				*w='\0';
				return 1;
			}
			ungetch(*w);
			break;
		}
		*w = '\0';
		return 1;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
/* buffer for ungetch */
/* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
/* push character back on input */
{
if (bufp >= BUFSIZE)
printf("ungetch: too many characters\n");
else
buf[bufp++] = c;
}
