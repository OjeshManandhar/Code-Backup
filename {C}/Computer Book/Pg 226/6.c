#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float pi=3.141592653589793;

float vol(float,float);

int main()
{
    float p,h;
    printf("Enter perimeter of the base of the cylinder: ");
    scanf("%f",&p);
    printf("Enter height of the cylinder: ");
    scanf("%f",&h);
    printf("\nVolume of the cylinder is %.2f.\n",vol(p,h));
    return 0;
}

float vol(float p,float h)
{
    float r,v;
    r=p/(2.0*pi);
    v=pi*r*r*h;
    return v;
}
