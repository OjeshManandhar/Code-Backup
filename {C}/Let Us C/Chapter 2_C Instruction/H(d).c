#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,n1,n2,n5,n10,n50,n100;
    printf("Enter a sum of money: ");
    scanf("%d",&n);
    n100=n/100;
    n50=(n%100)/50;
    n10=(n%50)/10;
    n5=(n%10)/5;
    n2=(n%5)/2;
    n1=n-(n100*100+n50*50+n10*10+n5*5+n2*2);
    printf("\nNumber of Re.1 note(s): %d\n",n1);
    printf("Number of Rs.2 note(s): %d\n",n2);
    printf("Number of Rs.5 note(s): %d\n",n5);
    printf("Number of Rs.10 note(s): %d\n",n10);
    printf("Number of Rs.50 note(s): %d\n",n50);
    printf("Number of Rs.100 note(s): %d\n",n100);
    return 0;
}
