#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <stdint.h>
#include <inttypes.h>

#define _BV(x) (1<<x)

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

int main()
{

    uint8_t n,a,b;
    printf("Enter a 8-bits (1-byte) unsigned integer: ");
    scanf("%u",&n);
    printf("\nThe 8-bits (1-byte) unsigned integer you've entered is: ");
    showbits(n);
    a=b=n;
    a>>=4;
    b<<=4;
    n=a|b;
    printf("\nExchanging the content of higher 4-bits with lower 4-bits, we get the following number: %d.\n",n);
    printf("The 8-bits (1-byte) new unsigned integer formed is: ");
    showbits(n);
    return 0;
}
