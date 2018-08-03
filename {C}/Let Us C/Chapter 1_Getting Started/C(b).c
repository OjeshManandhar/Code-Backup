#include <stdio.h>
#include <stdlib.h>

int main()
{
    float km,ft,cm,m,in;
    printf("Enter length in Kilometer: ");
    scanf("%f",&km);
    m=km/1000;
    cm=m/100;
    ft=km/0.000304;
    in=ft/0.083333;
    printf("\nDistance in meters: %f.\n",m);
    printf("Distance in feet: %f.\n",ft);
    printf("Distance in inches: %f.\n",in);
    printf("Distance in centimeter: %f.\n",cm);
    return 0;
}
