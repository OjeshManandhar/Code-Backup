#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <upper.h>

struct date
{
    unsigned int day: 5;
    unsigned int month: 4;
    unsigned int year: 12;
}*data=NULL;

int compare(const void *elem1, const void *elem2)
{
    struct date *x=(struct date *)elem1;
    struct date *y=(struct date *)elem2;

    return (x->year - y->year);
}

int main()
{
    int i,total=0,n;
    char c;
    do
    {
        total++;
        i=total-1;
        data=(struct date *)realloc(data,total*sizeof(struct date));
        printf("Enter the date of joining of %d employee:\n",i+1);
        printf("Enter day: ");
        scanf("%d",&n);
        data[i].day=n;
        printf("Enter month: ");
        scanf("%d",&n);
        data[i].month=n;
        printf("Enter year: ");
        scanf("%d",&n);
        data[i].year=n;
        printf("\n");
        do
        {
            printf("Add another data [Y/N]: ");
            fflush(stdin);
            c=getchar();
            c=cupr(c);
        }while (c!='N' && c!='Y');
        printf("\n");
    }while (c=='Y');
    printf("Press any key to continue...");
    getch();
    system("cls");
    puts("The entered data(s) sorted in ascending order are:\n");
    printf("Day \t Month \t Year\n");
    qsort(data,total,sizeof(struct date),compare);
    for (i=0;i<total;i++)
        printf("%-3d \t %-5d \t %d\n",data[i].day,data[i].month,data[i].year);
    return 0;
}
