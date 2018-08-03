#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,x;
    float *n,max,min;
    printf("Enter the number of numbers: ");
    scanf("%d",&x);
    printf("\n");
    n=(float *)malloc(x);
    printf("Enter the number no.1: ");
    scanf("%f",&n[1]);
    max=min=n[1];
    for (i=1;i<x;i++)
    {
        printf("Enter the number no.%d: ",i+1);
        scanf("%f",&n[i]);
        if (n[i]>max)
            max=n[i];
        else if (n[i]<min)
            min=n[i];
    }
    printf("\nThe greatest and smallest number are %.2f and %.2f respectively.\n",max,min);
    return 0;
}
