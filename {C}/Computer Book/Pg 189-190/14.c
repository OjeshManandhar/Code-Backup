#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b;
    char c;
    printf("Enter two numbers [SEPERATED BY A TAB]: ");
    scanf("%f%f",&a,&b);
    printf("\n%.2f + %.2f = %.2f\n\n",a,b,a+b);
    printf("%.2f - %.2f = %.2f\n",a,b,a-b);
    printf("%.2f - %.2f = %.2f\n\n",b,a,b-a);
    printf("%.2f x %.2f = %.2f\n\n",a,b,a*b);
    printf("%.2f / %.2f = %.2f\n",a,b,a*1.0/b*1.0);
    printf("%.2f / %.2f = %.2f\n\n",b,a,b*1.0/a*1.0);
    return 0;
}
