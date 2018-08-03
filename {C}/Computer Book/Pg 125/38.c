#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n,u,i;
    printf("Enter currency in Rs(NEPALI): ");
    scanf("%f",&n);
    u=n/100.0;
    i=n/1.6;
    printf("\nCurrency in US dollar and IC are %.2f and %.2f respectively.\n",u,i);
    return 0;
}
