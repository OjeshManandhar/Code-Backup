#include <stdio.h>
#include <stdlib.h>

int main()
{
    float l,b,h,a,v,sa;
    printf("Enter the LENGTH, BREADTH and HEIGHT of a box [SEPERATED BY A TAB]: ");
    scanf("%f%f%f",&l,&b,&h);
    a=l*b;
    v=a*h;
    sa=2*h*(l+b)+2*l*b;
    printf("\nThe AREA, VOLUME and AREA OF A FACE of the box are %.2f, %.2f and %.2f respectively.\n",a,v,sa);
    return 0;
}
