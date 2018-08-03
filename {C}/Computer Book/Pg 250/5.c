#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    float a,b,*x,*y;
    printf("Enter 2 different numbers [SEPERATED BY A TAB]: ");
    scanf("%f%f",&a,&b);
    x=&a;
    y=&b;
    printf("\nThe product of these numbers is: %.2f.\n",(*x)*(*y));
    return 0;
}
