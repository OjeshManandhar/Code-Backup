#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n[100],i,j;
    for (i=0;i<100;i++)
        n[i]=i+1;
    for (i=1;i<100;i++)
        if(n[i]!=0)
            for (j=i+1;j<100;j++)
                if (n[j]%n[i]==0)
                    n[j]=0;
    printf("The prime numbers between 1 and 100 are: \n");
    for (i=0;i<100;i++)
        if(n[i]!=0)
            printf("%d ",n[i]);
    printf("\n");
    return 0;
}
