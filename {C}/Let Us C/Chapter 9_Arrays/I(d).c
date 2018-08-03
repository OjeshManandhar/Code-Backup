#include <stdio.h>
#include <stdlib.h>

void modify(int *,int);
int main()
{
    int n[10],i;
    for (i=0;i<10;i++)
    {
        printf("Enter the %d no.: ",i+1);
        scanf("%d",&n[i]);
    }
    printf("\nThe numbers that you have entered are:\n\t");
    for (i=0;i<10;i++)
        printf("%d ",n[i]);
    modify(n,10);
    printf("\nThe numbers that you have entered are multiplied by 3,new numbers are :\n\t");
    for (i=0;i<10;i++)
        printf("%d ",n[i]);
    return 0;
}

void modify(int *num,int n)
{
    int i;
    for (i=0;i<n;i++)
        num[i]=num[i]*3;
}
