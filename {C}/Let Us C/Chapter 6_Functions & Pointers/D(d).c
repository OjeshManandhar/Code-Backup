#include <stdio.h>
#include <stdlib.h>

void leap(int);
int main()
{
    int y;
    printf("Enter a year: ");
    scanf("%d",&y);
    leap(y);
    return 0;
}

void leap(int p)
{
    if (p%4==0)
        printf("\nThe year is a LEAP YEAR.\n");
    else
        printf("\nThe year is NOT a LEAP YEAR.\n");
}
