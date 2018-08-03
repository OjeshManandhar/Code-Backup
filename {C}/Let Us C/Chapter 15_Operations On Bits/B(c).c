#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <stdint.h>
#include <inttypes.h>

#define _BV(x) (1<<x)

int checkbits(const unsigned int x, const unsigned int p, const unsigned int n)
{
    int i;
    for (i=p;i>=p-n;i--)
        if ((x&_BV(i))==0)
            return 0;
    return 1;
}

int main()
{
    unsigned int x,p,n,ans;
    printf("Enter a positive integer: ");
    scanf("%u",&x);
    printf("Enter the position to start checking from: ");
    scanf("%u",&p);
    printf("Enter the number of bits to check: ");
    scanf("%u",&n);
    ans=checkbits(x,p,n);
    if (ans==1)
        printf("\nTRUE.\n");
    else
        printf("\nFALSE.\n");
    return 0;
}
