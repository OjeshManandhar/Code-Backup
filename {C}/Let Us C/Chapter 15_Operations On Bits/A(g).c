#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdint.h>

int main()
{
    uint8_t i=32,j=65,k,l,m,n,o,p;
    k=i|35;
    l=~k;
    m=i&j;
    n=j^32;
    o=j<<2;
    p=i>>5;
    printf("k=%d l=%d m=%d\n",k,l,m);
    printf("n=%d o=%d p=%d\n",n,o,p);
    return 0;
}
