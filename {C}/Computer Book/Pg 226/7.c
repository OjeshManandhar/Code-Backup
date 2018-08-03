#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float si(float,float,float);

int main()
{
    float p,t,r;
    printf("Enter principal: ");
    scanf("%f",&p);
    printf("Enter time: ");
    scanf("%f",&t);
    printf("Enter rate: ");
    scanf("%f",&r);
    printf("\nSimple interest is: %.2f.\n",si(p,t,r));
    return 0;
}

float si(float p,float t,float r)
{
    return (p*t*r/100.0);
}
