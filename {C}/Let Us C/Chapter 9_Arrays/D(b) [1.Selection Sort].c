#include <stdio.h>
#include <stdlib.h>

void swap(int *,int *);
int main()
{
    int num[25],i,s,j;
    for (i=0;i<25;i++)
    {
        printf("Enter %d number: ",i+1);
        scanf("%d",&num[i]);
    }
    printf("\nThe entered numbers are in following order: \n");
    for (i=0;i<25;i++)
        printf("%d ",num[i]);
    for (i=0;i<25;i++)
        for (j=i+1;j<25;j++)
            if(num[i]>num[j])
                swap(&num[i],&num[j]);
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
