#include <stdio.h>
#include <stdlib.h>

int main()
{
    float t;
    printf("Enter the time taken by the worker: ");
    scanf("%f",&t);
    if (t>=2 && t<=3)
        printf("\nThe worker is highly efficient.\n");
    else if (t>=3 && t<=4)
        printf("\nThe worker needs to improve speed.\n");
    else if (t>=4 && t<=5)
        printf("\nThe worker needs to take training to improve speed.\n");
    else
        printf("\nThe worker is fired.\n");
    return 0;
}
