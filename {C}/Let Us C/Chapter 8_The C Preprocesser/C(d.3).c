#include <stdio.h>
#include <stdlib.h>
#include "header C(d).h"

int main()
{
    char a;
    printf("Enter a UPPER CASE alphabet:");
    scanf("%c",&a);
    printf("\nConverting %c to Small case.\n",a);
    CONVERT(a);
    return 0;
}
