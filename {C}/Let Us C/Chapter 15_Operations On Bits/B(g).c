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
    int i;
    int8_t n;
    printf("Enter a 8-bits signed integer: ");
    scanf("%d",&n);
    printf("\nThe 8-bits (1-byte) signed integer you've entered is: ");
    showbits(n);
    for (i=1;i<8;i+=2)
        n|=_BV(i);
    puts("\nChanging all the odd bits to 1.");
    printf("The newly formed signed integer is %d.\n",n);
    printf("\nThe 8-bits (1-byte) of the new signed integer formed is: ");
    showbits(n);
    return 0;
}
