#include <stdio.h>
#include <stdlib.h>

int main()
{
    float h,c,t;
    printf("Enter the value of HARDNESS of the steel: ");
    scanf("%f",&h);
    printf("Enter the value of CARBON CONTENT of the steel: ");
    scanf("%f",&c);
    printf("Enter the value of TENSILE STRENGTH of the steel: ");
    scanf("%f",&t);
    if (h>50 && c<0.7 && t>5600)
        printf("\nThe grade of the steel is: 10.\n");
    else if (h>50 && c<0.7)
        printf("\nThe grade of the steel is: 9.\n");
    else if (t>5600 && c<0.7)
        printf("\nThe grade of the steel is: 8.\n");
    else if (h>50 && t>5600)
        printf("\nThe grade of the steel is: 7.\n");
    else if (h>50 || c<0.7 || t>5600)
        printf("\nThe grade of the steel is: 6.\n");
    else
        printf("\nThe grade of the steel is: 5.\n");
    return 0;
}
