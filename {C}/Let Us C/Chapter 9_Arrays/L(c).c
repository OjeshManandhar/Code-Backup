#include <stdio.h>
#include <stdlib.h>

void swap(int *,int *);
int main()
{
    printf("Create a 4X4 matrix.\n");
    int n[4][4];
    int i,j,k,t;
    for (i=0;i<4;i++)
        for (j=0;j<4;j++)
        {
            printf("Enter the element [%d][%d]: ",i+1,j+1);
            scanf("%d",&n[i][j]);
        }
    printf("\nThe matrix you have created is:\n");
    for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
            printf("%d\t",n[i][j]);
        printf("\n");
    }
    for (k=0;k<3;k++)
    {
        for (i=k+1,j=k+1;i<=3;i++,j++)
            swap(&n[k][i],&n[j][k]);
    }
    printf("Transpose of the matrix is:\n");
    for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
            printf("%d\t",n[i][j]);
        printf("\n");
    }
    return 0;
}

void swap(int *a,int *b)
{
    int x;
    x=*a;
    *a=*b;
    *b=x;
}
