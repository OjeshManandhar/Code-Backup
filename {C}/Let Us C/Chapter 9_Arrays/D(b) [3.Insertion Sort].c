#include <stdio.h>
#include <stdlib.h>

void swap(int *,int *);
int main()
{
    int num[25],i,j,k;
    for (i=0;i<25;i++)
    {
        printf("Enter %d number: ",i+1);
        scanf("%d",&num[i]);
    }
    printf("\nThe entered numbers are in following order: \n");
    for (i=0;i<25;i++)
        printf("%d ",num[i]);
    for (i=1;i<=24;i++)
        for (j=0;j<i;j++)
            if (num[j]>num[i])
                for (k=j;k<i;k++)
                    swap(&num[i],&num[k]);
    printf("\n\nArranging in ascending order\n");
    for (i=0;i<25;i++)
        printf("%d ",num[i]);
    return 0;
}

void swap(int *a,int *b)
{
    int x;
    x=*a;
    *a=*b;
    *b=x;
}
