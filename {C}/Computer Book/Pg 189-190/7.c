#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n[10][5],t[10]={0,0,0,0,0,0,0,0,0,0},p[10];
    int i,j;
    printf("Enter marks obtained by,\nStudent No.\tSubject No.\n");
    for (i=0;i<10;i++)
    {
        for (j=0;j<5;j++)
        {
            printf("%d\t\t%d\t   :",i+1,j+1);
            scanf("%f",&n[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i=0;i<10;i++)
    {
        for (j=0;j<5;j++)
            t[i]+=n[i][j];
        p[i]=t[i]/500*100.0;
    }
    for (i=0;i<10;i++)
        if (p[i]>=75)
            printf("Student No.%d has acquired Distinction.\n",i+1);
        else if (p[i]>=60)
            printf("Student No.%d has acquired First Division.\n",i+1);
        else if (p[i]>=45)
            printf("Student No.%d has acquired Second Division.\n",i+1);
        else if (p[i]>=32)
            printf("Student No.%d has acquired Third Division.\n",i+1);
    return 0;
}
