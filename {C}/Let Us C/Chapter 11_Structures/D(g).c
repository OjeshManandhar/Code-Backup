#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct dates
{
    int year;
    int month;
    int day;
}data1,data2;

int compare(struct dates d1, struct dates d2)
{
    if (d1.year==d2.year && d1.month==d2.month && d1.day==d2.day)
        return 0;
    else
        return 1;
}

int main()
{
    printf("Enter the 2 dates.\n\n");
    printf("Enter the year of the first date: ");
    scanf("%d",&data1.year);
    printf("Enter the month of the first date: ");
    scanf("%d",&data1.month);
    printf("Enter the day of the first date: ");
    scanf("%d",&data1.day);
    printf("\nEnter the year of the second date: ");
    scanf("%d",&data2.year);
    printf("Enter the month of the second date: ");
    scanf("%d",&data2.month);
    printf("Enter the day of the second date: ");
    scanf("%d",&data2.day);
    if (compare(data1,data2)==0)
        printf("\nThe dates are equal.\n");
    else if (compare(data1,data2)==1)
        printf("\nThe dates are not equal.\n");
    return 0;
}
