#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,a3,b3,c3,d3,li;
    printf("Enter the number till which you want to find Ramanujan numbers: ");
    scanf("%d",&li);
    printf("\n");
    for (a=1;a<=li;a++)
    {
        a3=a*a*a;
        for (b=a;b<=li;b++)
        {
            b3=b*b*b;
            for (c=a+1;c<=li;c++)
            {
                c3=c*c*c;
                for (d=c;d<=li;d++)
                {
                    d3=d*d*d;
                    if (a3+b3==c3+d3)
                        printf("%d=%d^3+%d^3=%d^3+%d^3\n",a3+b3,a,b,c,d);
                }
            }
        }
    }
    return 0;
}
