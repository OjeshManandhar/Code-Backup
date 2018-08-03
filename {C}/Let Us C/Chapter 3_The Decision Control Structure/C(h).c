#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a;
    printf("Enter a number: ");
    scanf("%f",&a);
    if (a>=0)
        printf("\nThe absolute value of the number is: %f\n",a);
    else
        printf("\nThe absolute value of the number is: %f\n",a*-1);
    return 0;
}
