#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct emp
{
    int id;
    char *name;
    char *post;
    int sal;
}*data;

int compare(const struct emp *elem1, const struct emp *elem2)
{
    return (elem1->id - elem2->id);
}

int main()
{
    int n,i,l;
    char ch[50];
    printf("Enter the total number of data: ");
    scanf("%d",&n);
    data=(struct emp *)malloc(n*sizeof(struct emp));
    for (i=0;i<n;i++)
    {
        printf("\nEnter ID of employee no.%d :",i+1);
        scanf("%d",&data[i].id);
        fflush(stdin);
        printf("Enter NAME of employee no.%d :",i+1);
        gets(ch);
        l=strlen(ch)+1;
        data[i].name=(char *)malloc(l*sizeof(char));
        strcpy(data[i].name,ch);
        fflush(stdin);
        printf("Enter POST of employee no.%d :",i+1);
        gets(ch);
        l=strlen(ch)+1;
        data[i].post=(char *)malloc(l*sizeof(char));
        strcpy(data[i].post,ch);
        printf("Enter SALARY of employee no.%d :",i+1);
        scanf("%d",&data[i].sal);
    }
    qsort(data,n,sizeof(struct emp),compare);
    printf("\nAll data(s) have been entered. Press any key.");
    getch();
    system("cls");
    printf("ID\tName\tPost\tSalary\n");
    for (i=0;i<n;i++)
        printf("%d\t%s\t%s\t%d\n",data[i].id,data[i].name,data[i].post,data[i].sal);
    return 0;
}
