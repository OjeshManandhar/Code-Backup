#include <stdio.h>
#include <stdlib.h>

int main()
{
    float t;
    printf("Enter Temperature: ");
    scanf("%f",&t);
    if (t>=1 && t<=10)
        printf("\nThis temperature is suitable for FOOTBALL.\n");
    else if (t>=15 && t<=25)
        printf("\nThis temperature is suitable for BASKETBALL.\n");
    else if (t>=30 && t<=35)
        printf("\nThis temperature is suitable for CRICKET.\n");
    else if (t>=40 && t<=45)
        printf("\nThis temperature is suitable for SWIMMING.\n");
    else
        printf("\nNO MORE GAMES.\n");
    return 0;
}
