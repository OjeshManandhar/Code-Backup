#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mat[3][3]={
                    {10,5,9},
                    {5,3,12},
                    {25,35,20}
                  },rt[3]={},ct[3]={},g=0,i,j;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            rt[i]+=mat[i][j];
            ct[i]+=mat[j][i];
        }
        g+=rt[i]+ct[i];
    }
    printf("Branch/Items\tA\tB\tC\tRow Totals\n");
    for (i=0;i<4;i++)
    {
        if (i==0)
            printf("I\t\t");
        else if (i==1)
            printf("II\t\t");
        else if (i==2)
            printf("III\t\t");
        else if (i==3)
            printf("Column Totals\t");
        for (j=0;j<4;j++)
            if (j<3 && i<3)
                printf("%d\t",mat[i][j]);
            else if (j==3 && i<3)
                printf("%d\n",rt[i]);
            else if (i==3 && j<3)
                printf("%d\t",ct[j]);
            else if (i==3 && j==3)
                printf("%d\n",g);
    }
    return 0;
}
