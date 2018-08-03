#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b;
    printf("Enter 2 numbers(a and b) [SEPERATED BY A TAB]: ");
    scanf("%f%f",&a,&b);
    printf("\na+b = %.2f.\n",a+b);
    printf("a-b = %.2f.\n",a-b);
    printf("b-a = %.2f.\n",b-a);
    printf("a*b = %.2f.\n",a*b);
    printf("a/b = %.2f.\n",a/b);
    printf("b/a = %.2f.\n",b/a);
    return 0;
}
