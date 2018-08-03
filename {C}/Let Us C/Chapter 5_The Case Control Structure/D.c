#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c,n;
    printf("(1) First Class.\n");
    printf("(2) Second Class.\n");
    printf("(3) Third Class.\n");
    printf("Choose an class [OPTION NUMBER]: ");
    scanf("%d",&c);
    printf("Enter the number of subjects the student have failed in: ");
    scanf("%d",&n);
    switch (c)
    {
    case 1:
        if (n<=3)
            printf("\nGrace Marks: 5 marks.\n");
        else
            printf("\nNo Grace Marks.\n");
        break;
    case 2:
        if (n<=2)
            printf("\nGrace Marks: 4 marks.\n");
        else
            printf("\nNo Grace Marks.\n");
        break;
    case 3:
        if (n<=1)
            printf("\nGrace Marks: 5 marks.\n");
        else
            printf("\nNo Grace Marks.\n");
        break;
    }
    return 0;
}
