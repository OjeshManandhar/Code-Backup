#include <stdio.h>
#include <stdlib.h>

void swap(int *,int *);
int main()
{
    int num[25],i,j;
    for (i=0;i<25;i++)
    {
        printf("Enter %d number: ",i+1);
        scanf("%d",&num[i]);
    }
    printf("\nThe entered numbers are in following order: \n");
    for (i=0;i<25;i++)
        printf("%d ",num[i]);
    for (i=0;i<24;i++)
        for (j=0;j<24-c;j++) //for (j=0;j<24;j++)
            if (num[j]>num[j+1])
                swap(&num[j],&num[j+1]);
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
