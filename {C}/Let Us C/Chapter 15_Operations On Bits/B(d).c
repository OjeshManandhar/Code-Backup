#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <stdint.h>
#include <inttypes.h>

#define _BV(x) (1<<x)

int main()
{
    uint8_t n;
    printf("Enter a 8-bit unsigned integer: ");
    scanf("%u",&n);
    if (((n&_BV(3))!=0) && ((n&_BV(6))!=0) && ((n&_BV(7))!=0))
        printf("\nIts 3rd, 6th and 7th bit is turned on.\n");
    else
        printf("\nOne or all of 3rd, 6th and 7th bit is turned off.\n");
    return 0;
}
