#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key))
struct key {
char *word;
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
"struct",0,
"switch",0,
"ungetch",0,
"unsigned", 0,
"void", 0,
"volatile", 0,
"while", 0
};
int getword(char *, int);
struct key *binsearch(char *, struct key *, int);
/* count C keywords */
main()
{printf("%d %d",sizeof(struct key),sizeof keytab);
char word[MAXWORD];
struct key *p;
while (getword(word, MAXWORD) != 0)
if (isalpha(word[0]))
if ((p=binsearch(word, keytab, NKEYS)) != NULL)
p->count++;
for (p = keytab; p < keytab + NKEYS; p++)
if (p->count > 0)
printf("%4d %s\n", p->count, p->word);
return 0;
}
/* binsearch: find word in tab[0]...tab[n-1] */
struct key *binsearch(char *word, struct key *tab, int n)
{
int cond;
struct key *low = &tab[0];
struct key *high = &tab[n];
struct key *mid;
printf("%d",high-low);
while (low < high) {
mid = low + (high-low) / 2;
if ((cond = strcmp(word, mid->word)) < 0)
high = mid;
else if (cond > 0)
low = mid + 1;
else
return mid;
}
return NULL;
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
