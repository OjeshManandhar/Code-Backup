#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b;
    printf("Enter two numbers [SEPERATED BY A TAB]: ");
    scanf("%f%f",&a,&b);
    if (a<b)
        printf("\nSmallest number is %.2f.\n",a);
    else if (b<a)
        printf("\nSmallest number is %.2f.\n",b);
    else
        printf("\nBoth are equal.\n");
    return 0;
}
