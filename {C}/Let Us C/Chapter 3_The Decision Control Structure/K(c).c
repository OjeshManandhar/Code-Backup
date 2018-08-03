#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c;
    printf("Enter 3 numbers [SEPERATED BY A TAB]: ");
    scanf("%f%f%f",&a,&b,&c);
    a>b&&a>c ? printf("\n%.2f is the greatest.\n",a) : b>a&&b>c ? printf("\n%.2f is the greatest.\n",b) : printf("\n%.2f is the greatest.\n",c);
    return 0;
}
