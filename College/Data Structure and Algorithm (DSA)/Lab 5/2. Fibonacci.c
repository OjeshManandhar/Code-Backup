#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (fib(n - 1) + fib(n - 2));
}

int main()
{
    int i, n;

    printf("Enter number of terms to display: ");
    scanf("%d", &n);

    printf("\n");

    for (i = 0; i < n - 1; i++)
        printf("%d, ", fib(i));
    printf("\b\b & %d\n", fib(n - 1));

    return 0;
}
