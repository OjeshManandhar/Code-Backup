#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "areaperi.h"

int main()
{
    int x;
    float l,ps,as; //SUAREko variables|
    float a,b,c,pt,at,s; //TRIANGLEko variables|
    float r,pc,ac; //CIRCLEko variables|
    printf("You want to find AREA and PERIMETER of\n");
    printf("(1)  SQUARE\n");
    printf("(2)  TRIANGLE\n");
    printf("(3)  CIRCLE\n");
    printf("Enter your choice [1/2/3]: ");
    scanf("%d",&x);
    switch (x)
    {
    case 1:
        printf("\nEnter LENGTH: ");
        scanf("%f",&l);
        SQPERI(l,ps);
        SQAREA(l,as);
        printf("\nPerimeter: %.2f\n",ps);
        printf("Area: %.2f\n",as);
        break;
    case 2:
        printf("\nEnter LENGTH of 3 sides of the triangle [SEPERATED BY A TAB]: ");
        scanf("%f%f%f",&a,&b,&c);
        TRIPERI(a,b,c,pt);
        TRIAREA(a,b,c,at,s);
        printf("\nPerimeter: %.2f\n",pt);
        printf("Area: %.2f\n",at);
        break;
    case 3:
        printf("\nEnter RADIUS of the circle: ");
        scanf("%f",&r);
        CRIPERI(r,pc);
        CRIAREA(r,ac);
        printf("\nPerimeter: %.2f\n",pc);
        printf("Area: %.2f\n",ac);
        break;
    }
    return 0;
}
