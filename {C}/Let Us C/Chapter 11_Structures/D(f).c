#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct library
{
    int no;
    char *title;
    char *author;
    float price;
    int flag;
}*data=NULL,*temp=NULL;

int compare(const struct library *elem1, const struct library *elem2)
{
    return (elem1->no - elem2->no);
}

int main()
{
    int choice,f1=0,f3,f4,i,l,n=0,tn=0,bi,bni,an;
    char ch[25];
    while (1)
    {
        system("cls");
        printf("\t\tMAIN MENU\n");
        printf("1. Add book information\n");
        printf("2. Display book information\n");
        printf("3. List all books of given author\n");
        printf("4. List the title of specified book\n");
        printf("5. List the count of books in the library\n");
        printf("6. List the books in the order of accession number\n");
        printf("7. Exit\n\n");
        do
        {
            printf("Enter your choice: ");
            scanf("%d",&choice);
        }while(choice<1 || choice>7);
        switch (choice)
        {
            case 1:
                system("cls");
                printf("\t\t1. Add book information\n");
                printf("\nEnter the number of data to be entered this time: ");
                scanf("%d",&n);
                if (f1==0)
                {
                    if (n>0)
                        f1=1;
                    tn=n;
                    n=0;
                }
                else
                {
                    tn+=n;
                    n=tn-n;
                }
                data=(struct library*)realloc(data,tn*sizeof(struct library));
                for (i=n;i<tn;i++)
                {
                    printf("\nEnter the ACCESSION NUMBER of book no.%d: ",i+1);
                    scanf("%d",&data[i].no);
                    fflush(stdin);
                    printf("Enter the NAME of the book no.%d: ",i+1);
                    gets(ch);
                    l=strlen(ch);
                    data[i].title=(char *)calloc(l,sizeof(char));
                    strcpy(data[i].title,ch);
                    fflush(stdin);
                    printf("Enter the AUTHOR of book no.%d: ",i+1);
                    gets(ch);
                    l=strlen(ch);
                    data[i].author=(char *)calloc(l,sizeof(char));
                    strcpy(data[i].author,ch);
                    printf("Enter the price of the book no.%d: ",i+1);
                    scanf("%f",&data[i].price);
                    do
                    {
                        printf("Is the book no.%d ISSUED [1=YES 0=NO]: ",i+1);
                        scanf("%d",&data[i].flag);
                    }while (data[i].flag!=0 && data[i].flag!=1);
                }
                printf("\nAll data(s) have been entered. Press any key to go back to main menu.");
                getch();
                break;
            case 2:
                system("cls");
                printf("\t\t2. Display book information\n");
                if (f1==0)
                {
                    printf("\n\t\t\tNO DATA FOUND\n");
                    printf("\nPress any key to go back to main menu.");
                    getch();
                    break;
                }
                printf("\nAccession No.\tTitle\tAuthor\tPrice\tIssued\n");
                for (i=0;i<tn;i++)
                {
                    printf("%d\t\t%s\t%s\t%.2f\t",data[i].no,data[i].title,data[i].author,data[i].price);
                    if (data[i].flag==1)
                        printf("YES\n");
                    else
                        printf("NO\n");
                }
                printf("\nAll data(s) have been displayed. Press any key to go back to main menu.");
                getch();
                break;
            case 3:
                f3=0;
                system("cls");
                printf("\t\t3. List all books of given author\n");
                if (f1==0)
                {
                    printf("\n\t\t\tNO DATA FOUND\n");
                    printf("\nPress any key to go back to main menu.");
                    getch();
                    break;
                }
                fflush(stdin);
                printf("\nEnter the name of the author: ");
                gets(ch);
                for (i=0;i<tn;i++)
                    if (f3==0 && strcmp(data[i].author,ch)==0)
                    {
                        f3=1;
                        printf("\nAccession No.\tTitle\tAuthor\tPrice\tIssued\n");
                        printf("%d\t\t%s\t%s\t%.2f\t",data[i].no,data[i].title,data[i].author,data[i].price);
                        if (data[i].flag==1)
                            printf("YES\n");
                        else
                            printf("NO\n");
                    }
                    else if (f3==1 && strcmp(data[i].author,ch)==0)
                    {
                        printf("%d\t\t%s\t%s\t%.2f\t",data[i].no,data[i].title,data[i].author,data[i].price);
                        if (data[i].flag==1)
                            printf("YES\n");
                        else
                            printf("NO\n");
                    }
                if (f3==0)
                {
                    printf("\n\t\t\tNO DATA FOUND\n");
                    printf("\nPress any key to go back to main menu.");
                    getch();
                    break;
                }
                printf("\nAll data(s) have been displayed. Press any key to go back to main menu.");
                getch();
                break;
            case 4:
                f4=0;
                system("cls");
                printf("\t\t4. List the title of specified book\n");
                if (f1==0)
                {
                    printf("\n\t\t\tNO DATA FOUND\n");
                    printf("\nPress any key to go back to main menu.");
                    getch();
                    break;
                }
                printf("\nEnter accession number of the book: ");
                scanf("%d",&an);
                for (i=0;i<tn;i++)
                    if (f4==0 && data[i].no==an)
                    {
                        f4=1;
                        printf("\nAccession No.\tTitle\n");
                        printf("%d\t\t%s\n",data[i].no,data[i].title);
                    }
                    else if (f4==1 && data[i].no==an)
                        printf("%d\t\t%s\n",data[i].no,data[i].title);
                if (f4==0)
                {
                    printf("\n\t\t\tNO DATA FOUND\n");
                    printf("\nPress any key to go back to main menu.");
                    getch();
                    break;
                }
                printf("\nAll data(s) have been displayed. Press any key to go back to main menu.");
                getch();
                break;
            case 5:
                bi=bni=0;
                system("cls");
                printf("\t5. List the count of books in the library\n");
                if (f1==0)
                {
                    printf("\n\t\t\tNO DATA FOUND\n");
                    printf("\nPress any key to go back to main menu.");
                    getch();
                    break;
                }
                printf("\nTotal number of book(s) are: %d\n",tn);
                for (i=0;i<tn;i++)
                    if (data[i].flag==0)
                        bni++;
                    else
                        bi++;
                printf("Total no. of book(s) issued: %d\n",bi);
                printf("Total no. of book(s) in the library/books not issued: %d\n",bni);
                printf("\nAll data(s) have been displayed. Press any key to go back to main menu.");
                getch();
                break;
            case 6:
                system("cls");
                printf("\t6. List the books in the order of accession number\n");
                if (f1==0)
                {
                    printf("\n\t\t\tNO DATA FOUND\n");
                    printf("\nPress any key to go back to main menu.");
                    getch();
                    break;
                }
                temp=(struct library*)malloc(tn*sizeof(struct library));
                for (i=0;i<tn;i++)
                {
                    temp[i].no=data[i].no;
                    temp[i].title=(char *)malloc(sizeof(data[i].title));
                    strcpy(temp[i].title,data[i].title);
                    temp[i].author=(char *)malloc(sizeof(data[i].author));
                    strcpy(temp[i].author,data[i].author);
                    temp[i].price=data[i].price;
                    temp[i].flag=data[i].flag;
                }
                qsort(temp,tn,sizeof(struct library),compare);
                printf("\nAccession No.\tTitle\tAuthor\tPrice\tIssued\n");
                for (i=0;i<tn;i++)
                {
                    printf("%d\t\t%s\t%s\t%.2f\t",temp[i].no,temp[i].title,temp[i].author,temp[i].price);
                    if (temp[i].flag==1)
                        printf("YES\n");
                    else
                        printf("NO\n");
                }
                printf("\nAll data(s) have been displayed. Press any key to go back to main menu.");
                getch();
                free(temp);
                break;
            case 7:
                free((struct library *)data);
                exit(1);
                break;
        }
    }
    return 0;
}
