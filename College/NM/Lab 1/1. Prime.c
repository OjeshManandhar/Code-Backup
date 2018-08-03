#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, prime = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n == 0)
        printf("\nThe entered number is 0.\n");
    else
    {
        for (i = 2; i < n; i++)
            if (n%i == 0)
            {
                prime = 0;
                break;
            }

        if (prime == 1)
            printf("\n%d is prime.\n", n);
        else
            printf("\n%d is not prime.\n", n);
    }

    return 0;
}
