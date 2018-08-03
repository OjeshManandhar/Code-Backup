#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int c;
    float a,b;
    printf("Enter two numbers [SEPERATED BY A TAB]: ");
    scanf("%f%f",&a,&b);
    printf("\nChoose an option:\n");
    printf("1. Find SUM of these numbers.\n");
    printf("2. Find DIFFERENCE of these numbers.\n");
    printf("3. Find PRODUCT of these numbers.\n");
    printf("Enter your choice: ");
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        printf("\n\t\t1. Find SUM of these numbers.\n\n");
        printf("%.2f + %.2f = %.2f\n",a,b,a+b);
        break;
    case 2:
        printf("\n\t\t2. Find DIFFERENCE of these numbers.\n\n");
        printf("%.2f - %.2f = %.2f\n",a,b,a-b);
        printf("%.2f - %.2f = %.2f\n",b,a,b-a);
        break;
    case 3:
        printf("\n\t\t3. Find PRODUCT of these numbers.\n\n");
        printf("%.2f X %.2f = %.2f\n",a,b,a*b);
        break;
    default:
        printf("\nWrong Choice. Program terminated.\n");
    }
    return 0;
}
