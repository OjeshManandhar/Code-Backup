#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

struct customer
{
    int accno;
    char name[30];
    float balance;
}data;

struct trans
{
    int accno;
    char trans_type;
    float ammount;
}change;

int main()
{
    FILE *fc,*ft,*temp;
    int c,flag,f;
    char ch;
    float new_bal;
    fc=fopen("CUSTOMER.dat","rb+");
    if (fc==NULL)
    {
        fc=fopen("CUSTOMER.dat","ab+");
        if (fc==NULL)
        {
            perror("Can't open CUSTOMER.dat");
            exit(EXIT_FAILURE);
        }
    }
    ft=fopen("TRANSACTIONS.dat","rb");
    if (ft==NULL)
    {
        ft=fopen("TRANSACTIONS.dat","ab+");
        if (ft==NULL)
        {
            perror("Can't open TRANSACTIONS.dat");
            exit(EXIT_FAILURE);
        }
    }
    while (1)
    {
        do
        {
            system("cls");
            puts("\tMAIN MENU");
            puts("Choose an option.");
            puts("1. Add New Records.");
            puts("2. List Records");
            puts("3. Transactions Menu.");
            puts("4. List Transactions Records");
            puts("5. Exit");
            printf("Enter your choice: ");
            scanf("%d",&c);
        }while(c<1 || c>5);
        switch (c)
        {
        case 1:
            system("cls");
            fseek(fc,0,SEEK_END);
            puts("\t\tADDING NEW RECORDS");
            do
            {
                printf("\nEnter the ACCOUNT NUMBER of the customer: ");
                scanf("%d",&data.accno);
                printf("Enter NAME of the customer [MAX 29 CHARACTERS]: ");
                fflush(stdin);
                gets(data.name);
                printf("Enter the TOTAL BALANCE of the customer: ");
                scanf("%f",&data.balance);
                fwrite(&data,sizeof(struct customer),1,fc);
                printf("Add another record [Y/N]: ");
                fflush(stdin);
                ch=getchar();
            }while(ch=='y'|| ch=='Y');
            puts("\nAll record(s) have been entered.");
            printf("Press any key to go back to main menu...");
            getch();
            break;
        case 2:
            system("cls");
            puts("\t\tLIST OF RECORDS\n");
            rewind(fc);
            if (fread(&data,sizeof(struct customer),1,fc)!=1)
            {
                puts("NO DATA FOUND");
                printf("Press any key to go back to main menu...");
            }
            else
            {
                printf("Account No.\t%-29s\tBalance\n","Name");
                rewind(fc);
                while(fread(&data,sizeof(struct customer),1,fc)==1)
                    printf("%-11.5d\t%-29s\tRs. %.2f\n",data.accno,data.name,data.balance);
                puts("\nAll records have been displayed.");
                printf("Press any key to go back to menu...");
            }
            getch();
            break;
        case 4:
            system("cls");
            puts("\t\tLIST OF TRANSACTIONS RECORDS\n");
            rewind(ft);
            if (fread(&change,sizeof(struct trans),1,ft)!=1)
            {
                puts("NO DATA FOUND");
                printf("Press any key to go back to main menu...");
            }
            else
            {
                printf("Account No.\tType\tAmmount\n");
                rewind(ft);
                while(fread(&change,sizeof(struct trans),1,ft)==1)
                    printf("%-11.5d\t%-4c\tRs. %.2f\n",change.accno,toupper(change.trans_type),change.ammount);
                puts("\nAll records have been displayed.");
                printf("Press any key to go back to menu...");
            }
            getch();
            break;
        case 3:
            flag=0;
            f=0;
            new_bal=0;
            system("cls");
            puts("\t\tTRANSACTIONS MENU\n");
            rewind(fc);
            fseek(ft,0,SEEK_END);
            if (fread(&data,sizeof(struct customer),1,fc)!=1)
                puts("NO DATA FOUND");
            else
            {
                rewind (fc);
                printf("Enter the ACCOUNT NUMBER: ");
                scanf("%d",&change.accno);
                while(fread(&data,sizeof(struct customer),1,fc)==1)
                    if (change.accno==data.accno)
                    {
                        flag=1;
                        puts("\nAccount Details");
                        printf("Account No.: %.5d\n",data.accno);
                        printf("Account holder: %s\n",data.name);
                        printf("Total Balance: %.2f\n",data.balance);
                        printf("\nEnter TRANSACTION TYPE [D/W]: ");
                        fflush(stdin);
                        change.trans_type=getchar();
                        printf("Enter AMMOUNT: ");
                        scanf("%f",&change.ammount);
                        if (change.trans_type=='d' || change.trans_type=='D')
                        {
                            f=1;
                            new_bal=data.balance+change.ammount;
                            fwrite(&change,sizeof(struct trans),1,ft);
                        }
                        else if (change.trans_type=='w' || change.trans_type=='W')
                        {
                            if (data.balance-change.ammount<=100)
                            {
                                puts("\nRequest Denied.");
                                break;
                            }
                            else
                            {
                                f=1;
                                new_bal=data.balance-change.ammount;
                                fwrite(&change,sizeof(struct trans),1,ft);
                            }
                        }
                        else
                            puts("\nWrong Input.");
                        if (f==1)
                        {
                            temp=fopen("temporary.dat","wb");
                            rewind(fc);
                            while(fread(&data,sizeof(struct customer),1,fc)==1)
                                if (data.accno!=change.accno)
                                    fwrite(&data,sizeof(struct customer),1,temp);
                                else
                                {
                                    data.balance=new_bal;
                                    fwrite(&data,sizeof(struct customer),1,temp);
                                }
                            fclose(fc);
                            fclose(temp);
                            remove("CUSTOMER.dat");
                            rename("temporary.dat","CUSTOMER.dat");
                            fc=fopen("CUSTOMER.dat","rb+");
                        }
                        puts("\nRequest Acknowledged.");
                        break;
                    }
                if (flag==0)
                {
                    puts("\nNO DATA FOUND");
                }
            }
            printf("Press any key to go back to main menu...");
            getch();
            break;
        case 5:
            system("cls");
            printf("PROGRAM TERMINATED.\nPress any key to exit...");
            getch();
            exit(EXIT_SUCCESS);
        }
    }
    fclose(fc);
    fclose(ft);
    return 0;
}
