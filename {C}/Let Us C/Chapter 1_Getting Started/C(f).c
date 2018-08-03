#include <stdio.h>
#include <stdlib.h>

int main()
{
    float c,d,a;
    printf("Enter value of C:");
    scanf("%f",&c);
    printf("Enter value of D:");
    scanf("%f",&d);
    printf("\nExchanging Values.\n");
    a=c;
    c=d;
    d=a;
    printf("\nEnter value of C: %f.\n",c);
    printf("Enter value of D: %f.\n",d);
    return 0;
}
