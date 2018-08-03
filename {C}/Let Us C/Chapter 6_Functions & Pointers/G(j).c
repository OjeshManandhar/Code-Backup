#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float area(float,float,float);
int main()
{
    float a,b,c,ans;
    printf("Enter the length of three sides of a triangle [SEPERATED BY A TAB]: ");
    scanf("%f%f%f",&a,&b,&c);
    ans=area(a,b,c);
    printf("\nArea of the triangle is: %.2f.\n",ans);
    return 0;
}

float area(float a,float b,float c)
{
    float s,area;
    s=(a+b+c)/2.0;
    area=s*(s-a)*(s-b)*(s-c);
    return (pow(area,0.5));
}
