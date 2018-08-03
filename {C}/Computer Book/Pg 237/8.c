#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char *name;
    int roll;
}*data;

int compare(const struct student *elem1, const struct student *elem2)
{
    return (elem1->roll - elem2->roll);
}

int main()
{
    int n,i,l;
    char ch[50];
    printf("Enter the total number of data: ");
    scanf("%d",&n);
    data=(struct student *)malloc(n*sizeof(struct student));
    for (i=0;i<n;i++)
    {
        fflush(stdin);
        printf("\nEnter NAME of student no.%d :",i+1);
        gets(ch);
        l=strlen(ch)+1;
        data[i].name=(char *)malloc(l*sizeof(char));
        strcpy(data[i].name,ch);
        printf("Enter ROLL of employee no.%d :",i+1);
        scanf("%d",&data[i].roll);
    }
    qsort(data,n,sizeof(struct student),compare);
    printf("\nAll data(s) have been entered. Press any key.");
    getch();
    system("cls");
    printf("Name\tRoll\n");
    for (i=0;i<n;i++)
        printf("%s\t%d\n",data[i].name,data[i].roll);
    return 0;
}
