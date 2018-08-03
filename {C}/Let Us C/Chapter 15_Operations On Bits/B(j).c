#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <stdint.h>
#include <inttypes.h>

#define _BV(x) (1<<x)

/*
void showbits(const uint8_t n)
{
    int i;
    uint8_t k,andmask;

    for (i=7;i>=0;i--)
    {
        andmask=_BV(i);
        k=n&andmask;
        if (i!=7 && ((i+1)%4==0))
            printf(" ");
        k==0? printf("0"): printf("1");
    }
    printf("\n");
}
*/

void showbits(const int n)
{
    int i;
    for (i=31;i>=0;i--)
    {
        if (i!=31 && ((i+1)%4==0))
            printf(" ");
        (n&_BV(i))==0 ? printf("0") : printf("1");
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter a signed integer [32-bits]: ");
    scanf("%d",&n);
    puts("\nThe signed integer you've entered is:");
    showbits(n);
    return 0;
}
