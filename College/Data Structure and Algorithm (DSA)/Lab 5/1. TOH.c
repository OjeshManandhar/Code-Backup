#include <stdio.h>
#include <stdlib.h>

void tower(int n, char *from, char *to, char *aux)
{
    if (n == 0)
        return;

    tower(n - 1, from, aux, to);
    printf("Moved disk %d from %s to %s.\n", n, from, to);
    tower(n - 1, aux, to, from);
}

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("\n");

    if (n == 0)
        printf("No disk.\n");
    else
        tower(n, "Source", "Destination", "Auxiliary");

    return 0;
}
