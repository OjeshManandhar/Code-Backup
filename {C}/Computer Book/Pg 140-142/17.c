#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c,n;
    printf("Choose a class:\n");
    printf("1. Dress Circle.\n");
    printf("2. Balcony.\n");
    printf("3. First Class.\n");
    printf("4. Second Class.\n");
    printf("\nEnter your choice of class: ");
    scanf("%d",&c);
    printf("Enter the number of tickets: ");
    scanf("%d",&n);
    if (c==1)
        printf("\nTotal Cost: Rs.%d.\n",100*n);
    else if (c==2)
        printf("\nTotal Cost: Rs.%d.\n",75*n);
    else if (c==3)
        printf("\nTotal Cost: Rs.%d.\n",50*n);
    else if (c==4)
        printf("\nTotal Cost: Rs.%d.\n",40*n);
    return 0;
}
