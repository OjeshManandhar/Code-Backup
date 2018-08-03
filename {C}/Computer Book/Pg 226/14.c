#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <swap.h>

void search(float *n,int);

int main()
{
    int x,i;
    float *n;
    printf("Enter total number of numbers to process: ");
    scanf("%d",&x);
    n=(float *)malloc(x);
    for (i=0;i<x;i++)
    {
        printf("Enter number no.%d: ",i+1);
        scanf("%f",&n[i]);
    }
    search(n,x);
    return 0;
}

void search(float *n,int x)
{
    int i;
    float max=n[0];
    for (i=1;i<x;i++)
        if (n[i]>max)
            max=n[i];
    printf("\nThe maximum number is: %.2f.\n",max);
}
