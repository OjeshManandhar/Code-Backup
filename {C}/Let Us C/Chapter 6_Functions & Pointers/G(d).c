#include <stdio.h>
#include <stdlib.h>

void pfact(int,int);
int main()
{
    int n,i=2;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("\nThe prime factors of %d are: ",n);
    pfact(n,i);
    return 0;
}

void pfact(int n,int i)
{
    int j,f;
    if (n%i==0)
    {
        for (j=1,f=0;j<=i;j++)
            if (i%j==0)
                f++;
        if (f<=2)
            printf("%d ",i);
    }
    else
    {
        i++;
        pfact (n,i);
    }
    if (n/i==1)
        exit (1);
    else
        pfact (n/i,i);
}
