#include <stdio.h>
#include <stdlib.h>

void pfact(int);
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("\nThe prime factors of %d are: ");
    pfact(n);
    return 0;
}

void pfact(int n)
{
    int i=2,j,f=0;
    for (;i<=n;)
        if (n%i==0)
        {
            for (j=1,f=0;j<=i;j++)
                if (i%j==0)
                    f++;
            if (f<=2)
            {
                printf("%d ",i);
                n/=i;
            }
        }
    else
        i++;
}
