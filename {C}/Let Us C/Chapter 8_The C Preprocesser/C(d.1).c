#include <stdio.h>
#include <stdlib.h>
#include "header C(d).h"

int main()
{
    float a,b,m;
    printf("Enter two numbers [SEPERATED BYA TAB]: ");
    scanf("%f%f",&a,&b);
    MEAN(a,b,m);
    printf("\nThe mean of %.2f & %.2f is: %.2f.\n",a,b,m);
    return 0;
}
