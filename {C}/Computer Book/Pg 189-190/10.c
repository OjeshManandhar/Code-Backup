#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **mat1,**mat2,**ans,i,j,k,m,n,r;
    printf("If A and B be two matrices of size m x r and r x n then,\n");
    printf("Enter the value of m: ");
    scanf("%d",&m);
    printf("Enter the value of r: ");
    scanf("%d",&r);
    printf("Enter the value of n: ");
    scanf("%d",&n);
    mat1=(int **)malloc(m*sizeof(int *));
    for (i=0;i<m;i++)
        mat1[i]=(int *)malloc(r);
    mat2=(int **)malloc(r*sizeof(int *));
    for (i=0;i<r;i++)
        mat2[i]=(int *)malloc(m);
    ans=(int **)malloc(m*sizeof(int *));
    for (i=0;i<m;i++)
        ans[i]=(int *)malloc(n);
    printf("\n");
    for (i=0;i<m;i++)
    {
        for (j=0;j<r;j++)
        {
            printf("Enter the value of element %d x %d of matrix A: ",i+1,j+1);
            scanf("%d",&mat1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i=0;i<r;i++)
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
        for (j=0;j<r;j++)
            printf("%d\t",mat1[i][j]);
        printf("\n");
    }
    printf("\nThe matrix B you have created is shown below.\n");
    for (i=0;i<r;i++)
    {
        printf("\t");
        for (j=0;j<n;j++)
            printf("%d\t",mat2[i][j]);
        printf("\n");
    }
    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
            ans[i][j]=0;
    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
            for (k=0;k<r;k++)
                ans[i][j]+=mat1[i][k]*mat2[k][j];
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
