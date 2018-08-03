#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mul(float,float);

int main()
{
    float a,b;
    printf("Enter two numbers [SEPERATED BY A TAB]: ");
    scanf("%f%f",&a,&b);
    mul(a,b);
    return 0;
}

void mul(float a,float b)
{
    printf("\nThe product of %.2f and %.2f is %.2f.\n",a,b,a*b);
}
