#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n;
    float p=0.2,sum=0.0;
    printf("Enter the number of terms of the series: ");
    scanf("%d",&n);
    for (i=1;i<=n;i++,p+=0.2,sum+=p)
        printf("%.2f ",p);
    printf("\n\nSum of the series is %.2f and average is %.2f.\n",sum,sum/(n*1.0));
    return 0;
}
