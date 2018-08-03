#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <swap.h>

float search(float *n,int);

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
    printf("\nThe minimum number is: %.2f.\n",search(n,x));
    return 0;
}

float search(float *n,int x)
{
    int i;
    float m=n[0];
    for (i=1;i<x;i++)
        if (n[i]<m)
            m=n[i];
    return m;
}
