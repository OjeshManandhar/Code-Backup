#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float t,v,wcf;
    printf("Enter the temperature: ");
    scanf("%f",&t);
    printf("Enter the wind velocity: ");
    scanf("%f",&v);
    wcf=35.74+0.6215*t+(0.4275*t-35.75)*pow(v,0.16);
    printf("\nThe Wind Chill Factor is: %.2f.\n",wcf);
    return 0;
}
