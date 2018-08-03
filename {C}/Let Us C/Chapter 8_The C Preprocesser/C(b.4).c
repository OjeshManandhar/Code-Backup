#include <stdio.h>
#include <stdlib.h>
#include "header C(b).h"

int main()
{
    float a,b;
    printf("Enter two numbers [SEPERATED BY A TAB]:");
    scanf("%f%f",&a,&b);
    CHECK(a,b);
    return 0;
}
