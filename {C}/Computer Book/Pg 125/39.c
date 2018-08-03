#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,rev=0;
    printf("Enter a 4-digit number: ");
    scanf("%d",&n);
    rev+=(n%10)*1000;
    n/=10;
    rev+=(n%10)*100;
    n/=10;
    rev+=(n%10)*10;
    n/=10;
    rev+=n;
    printf("\nThe number in reverse format is: %d.\n",rev);
    return 0;
}
