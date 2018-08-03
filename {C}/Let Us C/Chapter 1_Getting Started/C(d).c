#include <stdio.h>
#include <stdlib.h>

int main()
{
    float cel,fah;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f",&fah);
    cel=(fah-32)*5/9;
    printf("\nTemperature in Centigrade is: %.2f.\n",cel);
    return 0;
}
