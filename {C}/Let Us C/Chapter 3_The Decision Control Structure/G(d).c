#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d;
    float fine=0;
    printf("Enter number of days the member is late to return the book: ");
    scanf("%d",&d);
    if (d<=5)
    {
        fine=d*0.5;
        printf("\nFine is: Rs.%.2f\n",fine);
    }
    else if (d<=10)
    {
        fine=2.5+(d-5);
        printf("\nFine is: Rs.%.2f\n",fine);
    }
    else if (d<=30)
    {
        fine=2.5+5+(d-10)*5;
        printf("\nFine is: Rs.%.2f\n",fine);
    }
    else
        printf("\nThe membership is canceled.\n");
    return 0;
}
