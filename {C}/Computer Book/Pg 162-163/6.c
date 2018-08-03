#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,s=0;
    for (i=1;i<=10;i++)
    {
        printf("Enter integer no.%d: ",i);
        scanf("%d",&n);
        if (n>0)
            s+=n;
    }
    printf("\nThe sum of non-negative numbers is %d.\n",s);
    return 0;
}
