#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c,d,e;
    printf("Enter the marks of 5 different subjects [SEPERATED BY A TAB]: ");
    scanf("%f%f%f%f%f",&a,&b,&c,&d,&e);
    printf("\nThe average marks is %.2f.\n",(a+b+c+d+e)/5.0);
    return 0;
}
