#include<stdio.h>
main()
{
char a[100];
int c,vb=0,i,j,b=0,s=0,q=0,sq=0,cmnt=0;
for(i=0;i<100&&(c=getchar())!=EOF&&c!='\n';++i){
	a[i]=c;
}
for(j=0;j<=i;++j){
if(a[j]=='{'){
++vb;
}
if(a[j]=='}'){
--vb;
}
if(a[j]=='('){
++b;
}
if(a[j]==')'){
--b;
}
if(a[j]=='['){
++s;
}
if(a[j]==']'){
--s;
}
if(a[j]=='"'){
++q;
}
if(a[j]==39){
++sq;
}
if(a[j]==42&&a[j-1]==47){
++cmnt;
}
if(a[j]==47&&a[j-1]==42){
--cmnt;
}
}
if(s!=0){
printf("square  bracket error\n");
}
if(vb!=0){
printf("valanja bracket error\n");
}
if(b!=0){
printf("bracket error\n");
}
if(cmnt!=0){
printf("comment error\n");
}
if((q%2)!=0){
printf("quotes error\n");
}
if((sq%2)!=0){
printf("single quotes error\n");
}

}
