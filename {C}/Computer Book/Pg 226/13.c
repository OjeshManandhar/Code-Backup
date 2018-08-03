#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <swap.h>

void sort(float n[10]);

int main()
{
    int i;
    float n[10];
    printf("Enter 10 different numbers.\n\n");
    for (i=0;i<10;i++)
    {
        printf("Enter number no.%d: ",i+1);
        scanf("%f",&n[i]);
    }
    sort(n);
    printf("\nThe numbers sorted in descending order are as follows:\n");
    for (i=0;i<10;i++)
        printf("%.2f\t",n[i]);
    return 0;
}

void sort(float n[10])
{
    int i,j;
    for (i=0;i<10;i++)
        for (j=i+1;j<10;j++)
            if(n[i]<n[j])
                swapf(&n[i],&n[j]);
}
