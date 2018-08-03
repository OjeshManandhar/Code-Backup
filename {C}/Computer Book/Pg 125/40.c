#include <stdio.h>
#include <stdlib.h>

int main()
{
    float m;
    printf("Enter time in minutes: ");
    scanf("%f",&m);
    printf("\nThe entered time in seconds is %.2f.\n",m*60.0);
    return 0;
}
