#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sn=0,sp=0,so=0,n;
    printf("The program is terminated when you enter zero(0).\n\n");
    do
    {
        printf("Enter a number: ");
        scanf("%d",&n);
        if (n<0)
            sn+=n;
        else if (n>0)
        {
            sp+=n;
            if (n%2!=0)
                so+=n;
        }
    }while(n!=0);
    printf("\nSum of Negative numbers, Positive numbers and Positive Odd numbers are ");
    printf("%d, %d and %d respectively.\n",sn,sp,so);
    return 0;
}
