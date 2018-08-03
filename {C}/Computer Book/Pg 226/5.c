#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sum(float,float);

int main()
{
    float a,b;
    printf("Enter any 2 numbers [SEPERATED BY A TAB]: ");
    scanf("%f%f",&a,&b);
    sum(a,b);
    return 0;
}

void sum(float a,float b)
{
    printf("\nSum of %.2f and %.2f is %.2f.\n",a,b,a+b);
    printf("i.e. %.2f + %.2f = %.2f.\n",a,b,a+b);
}
