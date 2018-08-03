#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,b,c,d,e,rev=0;
    printf("Enter a 5-digit number: ");
    scanf("%d",&n);
    a=n%10;
    rev=rev*10+a;
    b=(n/10)%10;
    rev=rev*10+b;
    c=(n/100)%10;
    rev=rev*10+c;
    d=(n/1000)%10;
    rev=rev*10+d;
    e=(n/10000)%10;
    rev=rev*10+e;
    if (rev==n)
        printf("\nThe given number is a PALINDROME.\n");
    else
        printf("\nThe given number is NOT a PALINDROME.\n");
    return 0;
}
