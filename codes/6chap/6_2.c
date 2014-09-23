#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<stdlib.h>
#define MAXWORD 100
struct tnode {
	char *word;
	int count;
	int set;
	struct tnode *left;
	struct tnode *right;
};
struct tnode *addtree(struct tnode *, char *,int set,int len);
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
main(int argc,char *argv[])
{
	int len=3;
	if(argc>1)
		len=(int)(atof(argv[1]));
	struct tnode *root;
	char word[MAXWORD];
	root = NULL;
	while (getword(word, MAXWORD) != 0)
		if (isalpha(word[0]))
			root = addtree(root, word,1,len);
	treeprint(root);
	return 0;
}
struct tnode *talloc(void)
{
        return (struct tnode *) malloc(sizeof(struct tnode));
}
struct tnode *talloc(void);
/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w,int set,int len)
{
	int cond;
	if (p == NULL) {
		p = talloc();
		p->word = strdup1(w);
		p->count = 1;
		p->set=set;
		p->left = p->right = NULL;
	} 	
	else if ((cond = strcmp1(w, p->word,len)) == 0){
		p->set=0;
		p->count++;
	}
	else if (cond ==-1)
		p->left = addtree(p->left, w,0,len);
	else if(cond==1)
		p->right = addtree(p->right, w,0,len);
	else if(cond==-2){
		p->left=addtree(p->left,w,1,len);
		p->set=1;
	}
	else if(cond==2){
		p->right=addtree(p->right,w,1,len);
		p->set=1;
	}
	return p;
}
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		if(p->set==1)
			printf("%s\n",p->word);
		treeprint(p->right);
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

int strcmp1(char *p,char *s,int len)
{
	char p1[100],s1[100];
	strcpy(p1,p);
	strcpy(s1,s);
	if(strcmp(p,s)==0)
		return 0;
	else if(strcmp(p,s)<0){
		if(strncmp(p,s,len)==0)
			return -2;
		return -1;
	}
	else if(strcmp(p,s)>0){
		if(strncmp(p,s,len)==0)
			return 2;
		return 1;
	}
}
