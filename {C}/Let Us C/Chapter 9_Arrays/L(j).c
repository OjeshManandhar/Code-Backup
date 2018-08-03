#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,n,i,j,k,**a,**b,**ans;
    printf("If A(x X n) and B(n X y) be two matrices then\n");
    printf("Enter the values of x,n,y [SEPERATED BY A TAB]: ");
    scanf("%d%d%d",&x,&n,&y);
    a=(int **)malloc(x*sizeof(int *));
    ans=(int **)calloc(x,sizeof(int *));
    for (i=0;i<x;i++)
    {
        a[i]=(int *)malloc(n*sizeof(int));
        ans[i]=(int *)calloc(y,sizeof(int));
    }
    b=(int **)malloc(n*sizeof(int *));
    for (i=0;i<n;i++)
        b[i]=(int *)malloc(y*sizeof(int));
    printf("\nEnter the elements of A(%d X %d)\n",x,n);
    for (i=0;i<x;i++)
        for (j=0;j<n;j++)
        {
            printf("Enter the element A(%d,%d): ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    printf("\nEnter the elements ofBA(%d X %d)\n",n,y);
    for (i=0;i<n;i++)
        for (j=0;j<y;j++)
        {
            printf("Enter the element B(%d,%d): ",i+1,j+1);
            scanf("%d",&b[i][j]);
        }
    printf("\nThe entered matrices are:\n");
    printf("1. Matrix A(%d X %d)\n",x,n);
    for (i=0;i<x;i++)
    {
        for (j=0;j<n;j++)
            printf("%-4d ",a[i][j]);
        printf("\n");
    }
    printf("2. Matrix B(%d X %d)\n",n,y);
    for (i=0;i<n;i++)
    {
        for (j=0;j<y;j++)
            printf("%-4d ",b[i][j]);
        printf("\n");
    }
    for (i=0;i<x;i++)
        for (j=0;j<y;j++)
            for (k=0;k<n;k++)
             ans[i][j]+=a[i][k]*b[k][j];
    printf("\nThe product of matrices A(%d X %d) and B(%d X %d) is C(%d X %d):\n",x,n,n,y,x,y);
    for (i=0;i<x;i++)
    {
        for (j=0;j<y;j++)
            printf("%-4d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}
