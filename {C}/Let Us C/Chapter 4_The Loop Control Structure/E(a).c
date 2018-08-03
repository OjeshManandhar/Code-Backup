#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=1,j,f;
    for (;i<=300;i++,f=0)
    {
        for (j=1;j<=i;j++)
            if (i%j==0)
                f++;
        if (f<=2)
            printf("%d\n",i);
    }
    return 0;
}
