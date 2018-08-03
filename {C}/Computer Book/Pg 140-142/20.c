#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m;
    printf("Enter month as a number: ");
    scanf("%d",&m);
    switch (m)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        printf("\nThe month has 31 days.\n");
        break;
    case 2:
        printf("\nThe month has 28 days and 29 days in leap year.\n");
        break;
    case 4: case 6: case 9: case 11:
        printf("\nThe month has 30 days.\n");
        break;
    default:
        printf("\nThe month is not contained in our calender.\n");
    }
    return 0;
}
