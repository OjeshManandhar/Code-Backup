#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <stdint.h>
#include <inttypes.h>

#define _BV(x) (1<<x)

void showbits(const uint16_t n)
{
    int i;
    uint16_t k,andmask;

    for (i=15;i>=0;i--)
    {
        andmask=_BV(i);
        k=n&andmask;
        if (i!=15 && ((i+1)%4==0))
            printf(" ");
        k==0? printf("0"): printf("1");
    }
    printf("\n");3
}

int main()
{

    uint16_t n,a,b;
    printf("Enter a 16-bits (2-bytes) unsigned integer: ");
    //scanf("%"SCNu16"",&n);
    //scanf("%" SCNu16,&n);
    scanf("%hu",&n);
    printf("\nThe 16-bits (2-bytes) unsigned integer you've entered is: ");
    showbits(n);
    a=b=n;
    a>>=8;
    b<<=8;
    n=a|b;
    printf("\nExchanging the content of the two bytes, we get the following number: %d.\n",n);
    printf("The 16-bits (2-bytes) new unsigned integer formed is: ");
    showbits(n);
    return 0;
}
