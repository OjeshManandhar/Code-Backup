#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float con(float);

int main()
{
    float t;
    printf("Enter temperature in celcius: ");
    scanf("%f",&t);
    printf("\nThe fahrenheit equivalance of this temperature is: %.2f.\n",con(t));
    return 0;
}

float con(float t)
{
    return ((9.0*t/5.0)+32.0);
}
