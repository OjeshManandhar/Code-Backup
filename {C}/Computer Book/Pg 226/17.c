#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float sum(float *num,int,int);

int main()
{
    int n,c,i;
    float *num;
    printf("Enter the number of numbers to process: ");
    scanf("%d",&n);
    printf("\n");
    num=(float *)malloc(n*sizeof(float));
    for (i=0;i<n;i++)
    {
        printf("Enter the number no.%d: ",i+1);
        scanf("%f",&num[i]);
    }
    printf("\nSum of all the numbers is: %.2f.\n",sum(num,n,1));
    return 0;
}

float sum(float *num,int n,int c)
{
    float s;
    if (n==c)
        return num[n-1];
    else
        s=num[c-1]+sum(num,n,c+1);
    return s;
}
