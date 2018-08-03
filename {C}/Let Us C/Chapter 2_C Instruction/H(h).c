#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a,x,y,sum;
    printf("Enter an angle in degree: ");
    scanf("%f",&a);
    x=pow(sin(a),2);
    y=pow(cos(a),2);
    sum=x+y;
    printf("\nSum of square of sine and cosine of %.2f degree(s) is: %.2f.\n",a,sum);
    return 0;
}
