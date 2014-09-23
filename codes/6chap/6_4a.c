#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<stdlib.h>
#define MAXWORD 100
int num;
struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
}keytab[5000];
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
char *strdup1(char *s)
{
        char *p;
        p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
        if (p != NULL)
                strcpy(p, s);
        return p;
}
main()
{
	struct tnode *root=keytab;
	char word[MAXWORD];
	while (getword(word, MAXWORD) != 0)
		if (isalpha(word[0]))
			root=addtree(root, word);
	treeprint(root);
	return 0;
}
struct tnode *talloc(void)
{
        return (struct tnode *) malloc(sizeof(struct tnode));
}
struct tnode *talloc(void);
/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
//	printf("%s\n",w);
	p[num].word=malloc(strlen(w)+1);
	strcpy(p[num].word,w);
//	printf("%s",p[num].word);
	num++;
	return p;
}
void treeprint(struct tnode *p)
{
	int n=0;printf("%d",num);
	while(n<num){
		printf("\n%s",p[n].word);
		n++;
	}
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
	if(c==EOF)
		return EOF;
	
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
		if (!isalnum(*w = getch())&&*w!='_'&&*w!='.') 
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
