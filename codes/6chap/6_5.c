#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define HASHSIZE 101
struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};
static struct nlist *hashtab[HASHSIZE];
unsigned hash(char *s)
{
	unsigned hashval;
	for (hashval = 0; *s != '\0'; s++){
	//	printf("%c %u\n",*s,hashval);
		hashval = *s + 31 * hashval;
	}//printf("hash[s]=%d\n",hashval%HASHSIZE);
	return hashval % HASHSIZE;
}
struct nlist *lookup(char *s)
{
	struct nlist *np;
	for (np = hashtab[hash(s)];np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;
	return NULL;	
}
struct nlist *lookup(char *);
//char *strdup(char *);
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;
	if ((np = lookup(name)) == NULL) {
//		np = (struct nlist *) malloc(sizeof(*np));
		np=malloc(sizeof(struct nlist *));
	if (np == NULL || (np->name = strdup(name)) == NULL)
		return NULL;
	hashval = hash(name);
//	np->next = hashtab[hashval];
	hashtab[hashval] = np;
	} else
	free((void *) np->defn);
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}
void *undef1(char *n)
{	
	struct nlist *np=hashtab[hash(n)];;
	if(strcmp(n,np->name)==0){
        	free(np->name);
        	free(np->defn);
		np->name==NULL;
	}
	else{
		for(np=hashtab[hash(n)];strcmp(np->next->name,n)!=0;np=np->next);
		np->next=np->next->next;
		free(np->next);
		free(np->next->name);
		free(np->next->defn);
	}
}
char *getop(void);
void customdefine(void)
{
	char v[23];
	char name[12];
	char defn[12];
	strcpy(v,getop());
	if(strcmp(v,"define")==0){
	strcpy(name,getop());
        strcpy(defn,getop());
//	printf("%s\t %s\t%s",v,defn,name);
	install(name,defn);
	}
}
void ungetch(int );
int getch(void);
char *getop(void)
{
	int c,i=0;
	char s[5678];
	char *sp=s;
	while((c=getch())==' '||c=='\t'||c=='\n');
	if(c=='#'){
		while((c=getch())==' '||c=='\t'||c=='\n');
		while(isalpha(c)){
			s[i]=c;
			c=getch();
			i++;
		}
		s[i]='\0';
	//	ungetch(c);
		if(strcmp(s,"define")==0)
			return sp;
		else 
			return NULL;
	}
	if(isalnum(c)){
	while(isalnum(c)){
                        s[i]=c;
                        c=getch();
                        i++;
                }
                s[i]='\0';
          //      ungetch(c);
//		printf("\n%s",sp);
                return sp;
	}
	
	
}
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
main()
{
	customdefine();
//	install("ab","1");
//	install("abh","0");
//	printf("%s",lookup("ab")->defn);
//      undef1("ab");
	if(lookup("ab")!=NULL){
		printf("\n%s",lookup("ab")->defn);
	}
}
