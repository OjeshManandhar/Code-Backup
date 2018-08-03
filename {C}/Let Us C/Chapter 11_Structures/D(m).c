#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct players
{
    int j1;
    int j2;
    int j3;
    int sum;
}data[5];

int main()
{
    int i,max,mvp=0;
    for (i=0;i<5;i++)
    {
        printf("Enter the rank of player no.%d\n",i+1);
        printf("Rank from judge no.1: ");
        scanf("%d",&data[i].j1);
        printf("Rank from judge no.2: ");
        scanf("%d",&data[i].j2);
        printf("Rank from judge no.3: ");
        scanf("%d",&data[i].j3);
        data[i].sum=data[i].j1+data[i].j2+data[i].j3;
        printf("\n");
    }
    max=data[0].sum;
    for (i=1;i<5;i++)
        if (data[i].sum>max)
        {
            max=data[i].sum;
            mvp=i+1;
        }
    printf("\nThe MVP is player no.: %d.\n",mvp);
    return 0;
}
