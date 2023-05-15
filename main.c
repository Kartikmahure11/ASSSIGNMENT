#include <stdio.h>
#include <stdlib.h>

int gtot=0,pst=0,sst=0,cst=0;

void menu()
{   printf("\n\n:: MENU :: \n\n");
    printf("1 PANEER PIZAA 120\n");
    printf("2 SANDWITCH     80\n");
    printf("3 COLD COFFEE  100\n");
    printf("0 Exit\n\n");
}
void quantity(int ch)
{    printf("ENTER THE NUMBER OF QUANTITY ");
     if(ch==3)
      printf("OF COLD COFFEE\n");
     else
     printf("\n");
}
void order(int rate,int ch)
{   int qty=0;
    quantity(ch);
    scanf("%d",&qty);
    switch(ch)
    {
    case 1:
         pst+=qty*rate;
        break;
    case 2:
         sst+=qty*rate;
        break;
    case 3:
         cst+=qty*rate;
        break;
    }
}
void cashReturn(int cash)
{
    int a[9]={500,200,100,50,20,10,5,2,1},c,i,x=0;
    c=cash;
    for(i=0;i<9;i++)
    {
        x=c/a[i];
        if(x!=0)
        printf("\n%d X %d = %d\n",a[i],x,a[i]*x);

        c=c%a[i];
    }
}
void billing()
{
    int cash=0;
    printf("ENTER THE CASH:");
    scanf("%d",&cash);
    if(cash>gtot)
    {
        cash=cash-gtot;
        printf("RETURN CASH : %d \n",cash);
        cashReturn(cash);

    }
    else if(cash<gtot)
    {
        gtot=gtot-cash;
        printf("please pay more : %d\n",gtot);
        billing();

    }
}
void bill(ch)
{
int k=0;
printf(":: YOUR BILL ::\n");
gtot=pst+sst+cst;
printf("-------------------------------------------------------------------------------- \n");
printf("SR.NO|\t   ITEM     \t|   QUANTITY\t| RATE \t|\t SUB TOTAL       \t|\n");
if(pst!=0||sst!=0||cst!=0)
printf("-------------------------------------------------------------------------------- \n");
if(pst!=0)
printf("%d    |\tPANEER PIZAA\t|\t%d   \t|  120 \t|          %d          \t|   \n",++k,pst/120,pst);
if(sst!=0)
printf("%d    |\tSANDWITCH   \t|\t%d   \t|   80 \t|          %d        \t\t|   \n",++k,sst/80,sst);
if(cst!=0)
printf("%d    |\tCOLD COFFEE \t|\t%d   \t|  100 \t|          %d          \t|   \n",++k,cst/100,cst);
if(pst!=0||sst!=0||cst!=0)
printf("-------------------------------------------------------------------------------- \n");
printf("\t                                     GRAND TOTAL = %d        \t\t|                                \n",gtot);
printf("-------------------------------------------------------------------------------- \n");
billing();
}

void userChoice()
{ int ch=0,l=1,rs;
      while(l)
    {
    menu();
    printf("ENTER YOUR CHOICE : ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("APNE PANEER PIZAA SELECT KIYA HAI!\n");
        order(120,ch);
        break;
    case 2:
        printf("APNE SANDWITCH SELECT KIYA HAI!\n");
        order(80,ch);
        break;
    case 3:
        printf("APNE COLD COFFEE SELECT KI HAI!\n");
        order(100,ch);
        break;
    case 0:
        l=0;
        bill();
        printf("EXIT!\n");
        break;
    default:
        printf("INVALID NUMBER!\n");
        break;
}
}
}
int main()
{
    printf("\3 \3 WELCOME TO LOVERS\3 CAFE \3 \3 \n\n");
    userChoice();
    printf("MILO FIR VAPUS KABHI !!\n");
    printf("DHANYAWAD!!\n");
    return 0;
    }
