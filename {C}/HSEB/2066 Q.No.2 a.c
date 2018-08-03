#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_int(int *a,int *b)
{
    int x;
    x=*a;
    *a=*b;
    *b=x;
}

void swap_string(char *a,char *b)
{
    char *x;
    x=(char *)malloc((strlen(a)+1)*sizeof(char));
    strcpy(x,a);
    strcpy(a,b);
    strcpy(b,x);
}

int main()
{
    struct student
    {
        char name[25];
        int marks;
    }data[20];
    int i,j;
    for (i=0;i<4;i++)
    {
        fflush(stdin);
        printf("Enter the NAME of student no.%d: ",i+1);
        gets(data[i].name);
        printf("Enter the MARKS of student no.%d:",i+1);
        scanf("%d",&data[i].marks);
        printf("\n");
    }
    printf("\nData as ENTERED:\n");
    printf("%-25s %-5s\n","Name","Roll");
    for (i=0;i<4;i++)
        printf("%-25s %-5d\n",data[i].name,data[i].marks);
    printf("\nSorting the data according with marks in descending order:\n");
    //Selection Sort
    /*for (i=0;i<3;i++)
        for (j=0;j<3-i;j++)
            if (data[j].marks<data[j+1].marks)
            {
                swap_int(&data[j].marks,&data[j+1].marks);
                swap_string(data[j].name,data[j+1].name);
            }
    */
    //Bubble Sort
    for (i=0;i<4;i++)
        for (j=i;j<4;j++)
        if (data[i].marks<data[j].marks)
        {
            swap_int(&data[i].marks,&data[j].marks);
            swap_string(data[i].name,data[j].name);
        }
    printf("%-25s %-5s\n","Name","Roll");
    for (i=0;i<4;i++)
        printf("%-25s %-5d\n",data[i].name,data[i].marks);
    return 0;
}
