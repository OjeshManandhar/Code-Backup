#include <stdio.h>
#include <stdlib.h>

int main()
{
    float p;
    printf("Enter percentage: ");
    scanf("%f",&p);
    if (p>=75.0)
        printf("\nDivision acquired is DISTINCTION.\n");
    else if (p>=60.0 && p<75.0)
        printf("\nDivision acquired is FIRST DIVISION.\n");
    else if (p>=45.0 && p<60.0)
        printf("\nDivision acquired is SECOND DIVISION.\n");
    else if (p>=32.0 && p<45.0)
        printf("\nDivision acquired is THIRD DIVISION.\n");
    else
        printf("\nHe/She has failed.\n");
    return 0;
}
