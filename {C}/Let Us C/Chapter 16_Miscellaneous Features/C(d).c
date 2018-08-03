#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <upper.h>

struct insurence
{
    unsigned char gender: 1;
    char type[6];
    char name[26];
    unsigned int duration: 16;
}*data=NULL;

int main()
{
    int i,total=0,n;
    char c;
    do
    {
        total++;
        i=total-1;
        data=(struct insurence *)realloc(data,total*sizeof(struct insurence));
        do
        {
            printf("Enter GENDER [M/F]: ");
            fflush(stdin);
            c=cupr(getchar());
        }while (c!='M' && c!='F');
        data[i].gender=c;
        do
        {
            printf("Enter policy TYPE [MAJOR / MINOR]: ");
            fflush(stdin);
            gets(data[i].type);
        }while (strcmpi(data[i].type,"major")!=0 && strcmpi(data[i].type,"minor")!=0);
        do
        {
            printf("Enter policy NAME: ");
            fflush(stdin);
            gets(data[i].name);
        }while (strlen(data[i].name)>25);
        printf("Enter policy DURATION [IN DAYS]: ");
        scanf("%d",&n);
        data[i].duration=n;
        printf("\n");
        do
        {
            printf("Enter another data [Y/N]: ");
            fflush(stdin);
            c=getchar();
            c=cupr(c);
        }while (c!='Y' && c!='N');
        printf("\n");
    }while (c=='Y');
    printf("Press any key...");
    getch();
    system("cls");
    puts("The data(s) you have entered is/are:\n");
    printf("%-6s \t %-5s \t %-25s \t Duration\n","Gender","Type","Name");
    for (i=0;i<total;i++)
    {
        if (data[i].gender=='M')
            printf("%-6s \t ","Male");
        else
            printf("Female \t ");
        printf("%s \t %-25s \t %d\n",data[i].type,data[i].name,data[i].duration);
    }
    return 0;
}
