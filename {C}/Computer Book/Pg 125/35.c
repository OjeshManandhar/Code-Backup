#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d,m,y;
    printf("Enter the number of days: ");
    scanf("%d",&d);
    y=d/365;
    d%=365;
    m=d/30;
    d%=30;
    printf("\nThe number of years, months and days are %d, %d and %d respectively.\n",y,m,d);
    return 0;
}
