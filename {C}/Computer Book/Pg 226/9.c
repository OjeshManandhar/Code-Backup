#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float check(float,float,float);

int main()
{
    float a,b,c;
    printf("Enter 3 different numbers [SEPERATED BY A TAB]: ");
    scanf("%f%f%f",&a,&b,&c);
    printf("\nThe greatest among them is: %.2f.\n",check(a,b,c));
    return 0;
}

float check(float a,float b,float c)
{
    if (a>b && a>c)
        return a;
    else if (b>a && b>c)
        return b;
    else if (c>a && c>b)
        return c;
}
