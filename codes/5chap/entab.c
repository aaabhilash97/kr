#include<stdlib.h>
#include<stdio.h>
main(int argc,char *argv[])
{
	int c,tabinc,pos=1,nt=0,nb=0;
	tabinc=(int)(atof(argv[1]));
	for(pos=1;(c=getchar())!=EOF;pos++){
		if(c==' '){
			if(pos % tabinc!=0)
				++nb;
			else
				nb=0;
				nt++;
		}
		else {
			for(;nt>0;--nt)
				putchar('\t');
			if(c=='\t')
				nb=0;
			else
				for(;nb>0;--nb)
					putchar(' ');
			putchar(c);
			if(c=='\n')
				pos=0;
			else if(c=='\t')
				pos=pos+(tabinc-(pos-1)%tabinc)-1;
		}
	}
}			
			
