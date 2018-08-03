#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r,s,a;
    printf("Enter age of Ram: ");
    scanf("%d",&r);
    printf("Enter age of Shyam: ");
    scanf("%d",&s);
    printf("Enter age of Ajay: ");
    scanf("%d",&a);
    if (r<s && r<a)
        printf("\nRam is YOUENGEST among them.\n");
    else if (s<r && s<a)
        printf("\nShyam is YOUENGEST among them.\n");
    else if (a<r && a<s)
        printf("\nAjay is YOUENGEST among them.\n");
    return 0;
}
