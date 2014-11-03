#include<stdio.h>
#include<stdlib.h>
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
		printf("%c %u\n",*s,hashval);
		hashval = *s + 31 * hashval;
	}printf("hash[s]=%d\n",hashval%HASHSIZE);
	return hashval % HASHSIZE;
}
struct nlist *lookup(char *s)
{
	struct nlist *np;
	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;
	return NULL;
}
struct nlist *lookup(char *);
char *strdup(char *);
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;
	if ((np = lookup(name)) == NULL) {
		np = (struct nlist *) malloc(sizeof(*np));
	if (np == NULL || (np->name = strdup(name)) == NULL)
		return NULL;
	hashval = hash(name);
	np->next = hashtab[hashval];
	hashtab[hashval] = np;
	} else
	free((void *) np->defn);
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}
main()
{
	
	install("ab","1");
//	install("IN","0");
	install("ab","9");
//	printf("%s",lookup("OUT")->defn);
	
	
}
