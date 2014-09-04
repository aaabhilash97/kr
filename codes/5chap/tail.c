#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ML 1000
char *lineptr[ML];
main(int argc,char *argv[])
{
	int nlines,i=0,len=(int)(atof(argv[1]));
	if((nlines=readlines(lineptr))>=0)
		while(i<nlines){
			printf("%s\n",(lineptr[i]+(strlen(lineptr[i]))-len));
				i++;
		}
}

int readlines(char *lineptr[])
{
	int len=0,nlines=0;
	char allocbuf[ML],line[ML];
	char *p,*alloccp=allocbuf;
	p=alloccp;
	while((len=getlines(line))>1){
		if(nlines>=ML||p>alloccp+ML)
			return nlines;
		else{
			strcpy(p,line);
			lineptr[nlines++]=p;
			p=p+len;
		}
	}return nlines;
}

int getlines(char *line)
{
	int i=0,c;
	for(;(c=getchar())!='\n';++i)
		*line++=c;
	*line='\0';
	return i+1;
}
