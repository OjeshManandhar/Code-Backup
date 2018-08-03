#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n;
    printf("Enter the number of terms of the series: ");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=i;j++)
            printf("1");
		for (j=1;j<i+1;j++)
			printf(" ");
    }
    return 0;
}
