#include <stdio.h>
#include <stdlib.h>

int power(int,int);
int main()
{
    int a,b,ans;
    printf("To find A^B\n");
    printf("Enter value of A: ");
    scanf("%d",&a);
    printf("Enter value of B: ");
    scanf("%d",&b);
    ans=power(a,b);
    printf("\nAnswer = A^B = %d.\n",ans);
    return 0;
}

int power(int a,int b)
{
    int i,f=1;
    for (i=1;i<=b;i++)
        f=f*a;
    return (f);
}
