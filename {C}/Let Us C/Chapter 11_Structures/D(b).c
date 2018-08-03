#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct bank
{
    int no;
    char *name;
    int bal;
}*data;

void display(int n)
{
    int f=0,i;
    for (i=0;i<n;i++)
        if (f==0 && data[i].bal<100)
        {
            f=1;
            printf("\nThe data(s) of customers having balance less than Rs.100 is/are:\n\n");
            printf("Account No.\tName\tBalance\n");
            printf("%d\t\t%s\tRs.%d\n",data[i].no,data[i].name,data[i].bal);
        }
        else if (f==1 && data[i].bal<100)
            printf("%d\t\t%s\tRs.%d\n",data[i].no,data[i].name,data[i].bal);
    if (f==0)
        printf("\n\tNO DATA FOUND.\n");
}

void request(int n)
{
    struct change
    {
        int n;
        int a;
        int code;
    }balance;
    int i;
    printf("\nEnter the ACCOUNT NUMBER: ");
    scanf("%d",&balance.n);
    printf("Enter the AMOUNT: ");
    scanf("%d",&balance.a);
    do
    {
        printf("Choose an option:\n");
        printf("1. Deposit\t\t0. Withdrawal\n");
        printf("Enter your choice: ");
        scanf("%d",&balance.code);
    }while(balance.code!=1 && balance.code!=0);
    for (i=0;i<n;i++)
        if (data[i].no==balance.n)
        {
            if (balance.code==1)
                data[i].bal=data[i].bal+balance.a;
            else
                if (data[i].bal-balance.a<100)
                {
                    printf("\nThe balance is insufficient for the specified withdrawal.\n");
                    return;
                }
                else
                    data[i].bal-=balance.a;
            break;
        }
    printf("\nThe request has been complete. The following data has changed\n");
    printf("Account No.\tName\tBalance\n");
    printf("%d\t\t%s\tRs.%d\n",data[i].no,data[i].name,data[i].bal);

}

int main()
{
    int i,n,l,c;
    char ch[50];
    do
    {
        system("cls");
        printf("Enter the total number of data [MAX=200]: ");
        scanf("%d",&n);
    }while(n>200);
    data=(struct bank *)malloc(n*sizeof(struct bank));
    for (i=0;i<n;i++)
    {
        printf("\nEnter the ACCOUNT NUMBER of customer no.%d: ",i+1);
        scanf("%d",&data[i].no);
        fflush(stdin);
        printf("Enter the NAME of customer no.%d: ",i+1);
        gets(ch);
        l=strlen(ch)+1;
        data[i].name=(char *)malloc(l*sizeof(char));
        strcpy(data[i].name,ch);
        printf("Enter the BALANCE IN ACCOUNT of customer no.%d: ",i+1);
        scanf("%d",&data[i].bal);
    }
    printf("\nAll data(s) have been entered.\n\n");
    printf("\t\tMAIN MENU\n");
    printf("Choose an option.\n");
    printf("1. Displaying the data(s) of customers having balance below Rs.100.\n");
    printf("2. Withdrawing or Depositing money\n");
    printf("\nEnter your choice: ");
    scanf("%d",&c);
    if (c==1)
        display(n);
    else
        request(n);
	free(data);
    return 0;
}
