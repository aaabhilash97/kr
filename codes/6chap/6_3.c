#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<stdlib.h>
#define MAXWORD 100
struct tnode {
	char *word;
	int count;
	int linenum[111];
	struct tnode *left;
	struct tnode *right;
};
int line=1;
struct tnode *addtree(struct tnode *, char *,int line);
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
	struct tnode *root;
	char word[MAXWORD];
	root = NULL;
	while (getword(word, MAXWORD) != EOF){
		if (isalpha(word[0]))
			root = addtree(root, word,line);
	}
	treeprint(root);
	return 0;
}
struct tnode *talloc(void)
{
        return (struct tnode *) malloc(sizeof(struct tnode));
}
struct tnode *talloc(void);
/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w,int n)
{
	int cond,enam=0;
	if (p == NULL) {
		p = talloc();
		p->word = strdup1(w);
		p->count = 1;
		p->linenum[enam]=n;
		p->left = p->right = NULL;
	} 	
	else if ((cond = strcmp(w, p->word)) == 0)
		{
			int enam=0;
			p->count++;
			while(p->linenum[enam]!=0)
				enam++;
				p->linenum[enam]=n;
			
				
				
				
		}
	else if (cond < 0)
		p->left = addtree(p->left, w,n);
	else
		p->right = addtree(p->right, w,n);
		return p;
}
void treeprint(struct tnode *p)
{
	int enam=0;
	if (p != NULL) {
		treeprint(p->left);
			printf("%4d %s", p->count, p->word);
			while(p->linenum[enam]!=0)
				printf(" %d",p->linenum[enam++]);
			printf("\n");
		treeprint(p->right);
	}
}

int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	while (isspace(c = getch()))
		if(c=='\n')
			line++;
	if(c==EOF)
		return EOF;
	if (c != EOF)
		*w++=c;
	if (!isalpha(c)) {
		if(c=='/'){
			if((c=getch())=='*'){
					while((c=getch())!='*')
						;
					if((c=getch())=='/'){
						;								}
			}
		}
	

		if(c=='"'){
			while((c=getch())!='"')
				;
		}
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())&&*w!='_') {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
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
