#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c,s,area;
    printf("Enter Length of 3 sides of the triangle [SEPERATED BY A TAB]: ");
    scanf("%f%f%f",&a,&b,&c);
    s=(a+b+c)/2;
    area=s*(s-a)*(s-b)*(s-c);
    printf("\nArea is: %.2f\n",area);
    return 0;
}
