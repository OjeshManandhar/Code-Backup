#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,s=0;
    printf("Enter the number of terms of the series: ");
    scanf("%d",&n);
    for (i=1;i<=n;s+=i*i,i++) //for (i=1;i<=n;i++,s+=i*i) ra for (i=1;i<=n;++i,s+=i*i) nagarne|
        printf("%d ",i*i);
    printf("\nSum of the series is %d.\n",s);
    return 0;
}
