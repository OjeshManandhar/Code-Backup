#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y;
    printf("Enter a year: ");
    scanf("%d",&y);
    y%4==0 ? printf("\nLEAP YEAR.\n") : printf("\nNOT a LEAP YEAR.\n");
    return 0;
}
