#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,p=1,sum=0;;
    for (i=1;i<=10;i++,p+=4,sum+=p)
        printf("%d ",p);
    printf("\n\nSum of the series is %d and average is %.2f.\n",sum,sum/10.0);
    return 0;
}
