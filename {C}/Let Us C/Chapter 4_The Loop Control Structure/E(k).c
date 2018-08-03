#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i;
    float p,q,r,n,a;
    for (i=1;i<=10;i++)
    {
        printf("Enter PRINCIPAL AMMOUNT: ");
        scanf("%f",&p);
        printf("Enter number of times INTREST COMPOUNDS per year: ");
        scanf("%f",&q);
        printf("Enter number of YEARS: ");
        scanf("%f",&n);
        printf("Enter ANNUAL RATE: ");
        scanf("%f",&r);
        a=p*pow((1+r/q),n*q);
        printf("\nAmount: %.2f\n\n\n",a);
    }
    return 0;
}
