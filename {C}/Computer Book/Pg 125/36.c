#include <stdio.h>
#include <stdlib.h>

int main()
{
    float b,h;
    printf("Enter the values of BASE and HEIGHT of a triangle [SEPERATED BY A TAB]: ");
    scanf("%f%f",&b,&h);
    printf("\nThe area of the triangle is %.2f.\n",(1/2.0)*b*h);
    return 0;
}
