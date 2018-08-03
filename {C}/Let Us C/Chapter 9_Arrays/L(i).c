#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[6][6],b[6][6],ans[6][6],i,j;
    printf("Create two 6X6 matrices i.e. 'A' & 'B'.\n");
    printf("\nEnter the elements of matrix 'A':\n");
    for (i=0;i<6;i++)
        for (j=0;j<6;j++)
        {
            printf("Enter the element A[%d][%d]: ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    printf("\n\nEnter the elements of matrix 'B':\n");
    for (i=0;i<6;i++)
        for (j=0;j<6;j++)
        {
            printf("Enter the element B[%d][%d]: ",i+1,j+1);
            scanf("%d",&b[i][j]);
        }
    printf("\n\nThe matrices you have created are:\n");
    printf("\nMatrix A:\n");
    for (i=0;i<6;i++)
    {
        for (j=0;j<6;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("\n\nMatrix B:\n");
    for (i=0;i<6;i++)
    {
        for (j=0;j<6;j++)
            printf("%d ",b[i][j]);
        printf("\n");
    }
    printf("\n\nThe sum of the two matrices 'A' & 'B' is:\n");
    for (i=0;i<6;i++)
    {
        for (j=0;j<6;j++)
        {
            ans[i][j]=a[i][j]+b[i][j];
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
