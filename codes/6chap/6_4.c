#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<stdlib.h>
#define MAXWORD 100
struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};
struct tnode *addtree(struct tnode *, char *);
struct tnode *root1=NULL;
void treeprint(struct tnode *);
int getword(char *, int);
char *save[10];
char *strdup1(char *s)
{
        char *p;
        p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
        if (p != NULL)
                strcpy(p, s);
        return p;
}
struct tnode *talloc(void);
struct tnode *newaddtree(struct tnode *p, struct tnode *w)
{
        int cond;
        if (p == NULL) {
                p = talloc();
                p->word = strdup1(w->word);
                p->count = w->count;
                p->right =p->left= NULL;
        }
        else if (p->count==w->count)
                {
                        p->left=newaddtree(p->left,w);
                }
        else if (w->count<p->count)
                p->left = newaddtree(p->left, w);
        else 
                p->right = newaddtree(p->right, w);
                return p;
}
void treeprint1(struct tnode *p)
{
	if(p!=NULL){
		root1=newaddtree(root1,p);
		treeprint1(p->right);
	}
}
main()
{
	struct tnode *root;
	char word[MAXWORD];
	int count=1;
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);
	treeprint1(root);
	treeprint(root1);
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
	int cond;
	if (p == NULL) {
		p = talloc();
		p->word = strdup1(w);
		p->count = 1;
		p->right = NULL;
	} 	
	else if ((cond = strcmp(w, p->word)) == 0)
		{
			p->count++;
		}
	else if (cond < 0)
		p->right = addtree(p->right, w);
	else
		p->right = addtree(p->right, w);
		return p;
}
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch())){
		/*if (c=='\n'){
			return 0*/;
	//	}
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
