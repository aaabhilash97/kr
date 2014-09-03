#include<stdio.h>
main()
{
int select;
float fahr,kel,cel;
loop:
printf("1.cel2kel\n2.cel2fah\n3.exit\n");
scanf("%d",&select);
if(select==1)
{
for(cel=0;cel<=300;cel=cel+20){
kel=cel+270;
printf("%3.1f \t %6.2f\n",cel,kel);
}
goto loop;
}
if(select==2)
{
while(cel<=300){
fahr=(9.0/5.0)*cel+(32.0);
printf("%3.0f\t\t%6.2f\n",cel,fahr);
cel=cel+20;
}
goto loop;
}
if(select!=1&&select!=2&&select!=3)
{
printf("invalid input enter1 0r 2\n\n");
goto loop;
}
if(select!=1&&select!=2&&select!=3)
{

}
}
