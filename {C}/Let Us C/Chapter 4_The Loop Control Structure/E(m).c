#include <stdio.h>
#include <stdlib.h>

int main()
{
    int l,b,h,i=1;
    for (l=1;l<=30;l++)
        for (b=1;b<=30;b++)
            for (h=1;h<=30;h++)
                if (h*h==l*l+b*b)
                {
                    printf("(%d)\tL=%d\tB=%d\tH=%d\n",i,l,b,h);
                    i++;
                }
    return 0;
}
