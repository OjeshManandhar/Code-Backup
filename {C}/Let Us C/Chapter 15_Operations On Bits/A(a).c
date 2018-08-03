#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define _BV(x) (1<<x)

int main()
{
    int n,i;
    char color,*arr[]={"Violet","Indigo","Blue","Green","Yellow","Orange","Red"};
    printf("Enter a number: ");
    scanf("%d",&n);
    if (n==0)
        puts("\nNo colours are present.");
    else
    {
        puts("\nThe colours of rainbow which are present are:");
        for (i=0;i<7;i++)
        {
            color=n&_BV(i);
            if (color!=0)
                puts(arr[i]);
        }
    }
    return 0;
}
