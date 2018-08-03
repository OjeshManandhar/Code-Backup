#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    printf("Enter an CHARACTER:");
    scanf("%c",&ch);
    (ch>=97&&ch<=122)||(ch>=65&&ch<=90)||(ch>=48&&ch<=57) ? printf("\nNOT a SPECIAL SYMBOL.\n") : printf("\nSPECIAL SYMBOL.\n");
    return 0;
}
