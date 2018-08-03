#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **mat1,**mat2,**ans,i,j,m,n;
    printf("If m x n be the size of the two matrices (say A and B) then,\n");
    printf("Enter the value of m: ");
    scanf("%d",&m);
    printf("Enter the value of n: ");
    scanf("%d",&n);
    mat1=(int **)malloc(m*sizeof(int *));
    for (i=0;i<m;i++)
        mat1[i]=(int *)malloc(n);
    mat2=(int **)malloc(m*sizeof(int *));
    for (i=0;i<m;i++)
        mat2[i]=(int *)malloc(n);
    ans=(int **)malloc(m*sizeof(int *));
    for (i=0;i<m;i++)
        ans[i]=(int *)malloc(n);
    printf("\n");
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("Enter the value of element %d x %d of matrix A: ",i+1,j+1);
            scanf("%d",&mat1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("Enter the value of element %d x %d of matrix B: ",i+1,j+1);
            scanf("%d",&mat2[i][j]);
        }
        printf("\n");
    }
    printf("\nThe matrix A you have created is shown below.\n");
    for (i=0;i<m;i++)
    {
        printf("\t");
        for (j=0;j<n;j++)
            printf("%d\t",mat1[i][j]);
        printf("\n");
    }
    printf("\nThe matrix B you have created is shown below.\n");
    for (i=0;i<m;i++)
    {
        printf("\t");
        for (j=0;j<n;j++)
            printf("%d\t",mat2[i][j]);
        printf("\n");
    }
    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
            ans[i][j]=mat1[i][j]+mat2[i][j];
    printf("\nThe sum of these two matrices is shown below.\n");
    for (i=0;i<m;i++)
    {
        printf("\t");
        for (j=0;j<n;j++)
            printf("%d\t",ans[i][j]);
        printf("\n");
    }
    return 0;
}
