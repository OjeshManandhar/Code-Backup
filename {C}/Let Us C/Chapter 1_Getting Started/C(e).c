#include <stdio.h>
#include <stdlib.h>

int main()
{
    float len,bre,rad,peri,cir,arec,acir;
    printf("Enter Length of the Rectangle: ");
    scanf("%f",&len);
    printf("Enter Breadth of the Rectangle: ");
    scanf("%f",&bre);
    printf("Enter Radius of the Circle: ");
    scanf("%f",&rad);
    peri=2*(len+bre);
    arec=len*bre;
    cir=2*3.14*rad;
    acir=3.14*rad*rad;
    printf("Area of Rectangle is: %.2f\n",arec);
    printf("Perimeter of Rectangle is: %.2f\n",peri);
    printf("Area of Circle is: %.2f\n",cir);
    printf("Circumference of Circle is: %.2f\n",acir);
    return 0;
}
