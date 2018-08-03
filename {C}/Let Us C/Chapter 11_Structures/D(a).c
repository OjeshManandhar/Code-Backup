#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int *roll;
    char **name;
    char **dept;
    char **cou;
    int *year;
}data;

void display_year(int n)
{
    int y,f=0,i;
    system("cls");
    printf("Enter the YEAR: ");
    scanf("%d",&y);
    printf("\n");
    for (i=0;i<n;i++)
        if (f==0 && data.year[i]==y)
        {
            f=1;
            printf("The data(s) of students joining in %d is/are:\n\n",y);
            printf("Roll\tName\t\tDepartment\tCourse\tYear\n");
            printf("%d\t%s\t\t%s\t\t%s\t%d\n",data.roll[i],data.name[i],data.dept[i],data.cou[i],data.year[i]);
        }
        else if (f==1 && data.year[i]==y)
            printf("%d\t%s\t\t%s\t\t%s\t%d\n",data.roll[i],data.name[i],data.dept[i],data.cou[i],data.year[i]);
    if (f==0)
        printf("\tNO DATA FOUND.\n");
}

void display_roll(int n)
{
    int r,f=0,i;
    system("cls");
    printf("Enter the ROLL NUMBER: ");
    scanf("%d",&r);
    printf("\n");
    for (i=0;i<n;i++)
        if (f==0 && data.roll[i]==r)
        {
            f=1;
            printf("The data(s) of students with roll no. %d is/are:\n\n",r);
            printf("Roll\tName\t\tDepartment\tCourse\tYear\n");
            printf("%d\t%s\t\t%s\t\t%s\t%d\n",data.roll[i],data.name[i],data.dept[i],data.cou[i],data.year[i]);
        }
        else if (f==1 && data.roll[i]==r)
            printf("%d\t%s\t\t%s\t\t%s\t%d\n",data.roll[i],data.name[i],data.dept[i],data.cou[i],data.year[i]);
    if (f==0)
        printf("\tNO DATA FOUND.\n");
}

int main()
{
    int n,i,l,c;
    char ch[50];
    do
    {
        system("cls");
        printf("Enter the total number of data [MAX=450]: ");
        scanf("%d",&n);
    }while(n>450);
    data.roll=(int *)malloc(n*sizeof(int));
    data.name=(char **)malloc(n*sizeof(char *));
    data.dept=(char **)malloc(n*sizeof(char *));
    data.cou=(char **)malloc(n*sizeof(char *));
    data.year=(int *)malloc(n*sizeof(int));
    for (i=0;i<n;i++)
    {
        printf("\n");
        printf("Enter the ROLL NUMBER of student no.%d: ",i+1);
        scanf("%d",&data.roll[i]);
        fflush(stdin);
        printf("Enter the NAME of student no.%d: ",i+1);
        gets(ch);
        l=strlen(ch)+1;
        data.name[i]=(char *)malloc(l*sizeof(char));
        strcpy(data.name[i],ch);
        fflush(stdin);
        printf("Enter the DEPARTMENT of student no.%d: ",i+1);
        gets(ch);
        l=strlen(ch)+1;
        data.dept[i]=(char *)malloc(l*sizeof(char));
        strcpy(data.dept[i],ch);
        fflush(stdin);
        printf("Enter the COURSE of student no.%d: ",i+1);
        gets(ch);
        l=strlen(ch)+1;
        data.cou[i]=(char *)malloc(l*sizeof(char));
        strcpy(data.cou[i],ch);
        printf("Enter the YEAR OF JOINING of student no.%d: ",i+1);
        scanf("%d",&data.year[i]);
    }
    printf("\nAll data(s) have been entered. Press any key.");
    getch();
    system("cls");
    printf("\t\t\tMAIN MENU\n\n");
    printf("Choose an option.\n");
    printf("1. Displaying the data(s) of students joining in particular year.\n");
    printf("2. Displaying data of student with particular roll number.");
    printf("\nEnter your choice: ");
    scanf("%d",&c);
    if (c==1)
        display_year(n);
    else if (c==2)
        display_roll(n);
	free(data.roll);
	free(data.name);
	free(data.dept);
	free(data.cou);
	free(data.year);
    return 0;
}
