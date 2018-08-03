#include <stdio.h>
#include <stdlib.h>

void shift(int *,int *,int *);
int main()
{
    int a,b,c,i;
    printf("Enter 3 different numbers [SEPERATED BY A TAB]: ");
    scanf("%d%d%d",&a,&b,&c);
    printf("\nBefore shifting the values.\n");
    printf("Values of:\n");
    printf("\tx=%d\ty=%d\tz=%d\n",a,b,c);
    printf("\nShifting the values to right.\n");
    shift(&a,&b,&c);
    printf("Values of:\n");
    printf("\ty=%d\tz=%d\tx=%d\n",b,c,a);
    printf("\tx=%d\ty=%d\tz=%d\n",a,b,c);
    return 0;
}

void shift(int *x,int *y,int *z)
{
    int a;
    a=*x;
    *x=*z;
    *z=*y;
    *y=a;
}
