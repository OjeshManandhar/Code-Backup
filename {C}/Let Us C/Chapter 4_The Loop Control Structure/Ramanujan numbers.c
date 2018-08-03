#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,b,c,d,a3,b3,c3,d3;
    printf("Enter the limit: ");
    scanf("%d",&n);
    for(a=1;a<=n;a++)
    {
        a3=a*a*a;
        if(a3>n)
            break;
        for(b=a;b<=n;b++)
        {
            b3=b*b*b;
            if(a3+b3>n)
                break;
            for(c=a+1;c<=n;c++)
            {
                c3=c*c*c;
                if(c3>a3+b3)
                    break;
                for(d=c;d<=n;d++)
                {
                    d3=d*d*d;
                    if(c3+d3>a3+b3)
                        break;
                    if(c3+d3==a3+b3)
                        printf("%d=%d^3+%d^3=%d^3+%d^3\n",(a3+b3),a,b,c,d);
                }
            }
        }
    }
    return 0;
}
