#include <stdio.h>
#include <stdlib.h>

int main()
{
    float w,h,b;
    printf("Enter the WEIGHT of he person: ");
    scanf("%f",&w);
    printf("Enter the HEIGHT of he person: ");
    scanf("%f",&h);
    b=w/(h*h);
    if (b<=15)
        printf("\nBMI Category: Starvation.\n");
    else if (b>=15.1 && b<=17.5)
        printf("\nBMI Category: Anorexic.\n");
    else if (b>=17.6 && b<=18.5)
        printf("\nBMI Category: Underweight.\n");
    else if (b>=18.6 && b<=24.9)
        printf("\nBMI Category: Ideal.\n");
    else if (b>=25 && b<=25.9)
        printf("\nBMI Category: Overweight.\n");
    else if (b>=30 && b<=30.9)
        printf("\nBMI Category: Obese.\n");
    else
        printf("\nBMI Category: Morbidly Obese.\n");
    return 0;
}
