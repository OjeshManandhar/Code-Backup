#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <strtoint.h>

int main()
{
    char n[10];
    int i,c=10,x=0;
    printf("Enter the 10-digit ISBN number: ");
    gets(n);
    for(i=0;i<9;i++,c--)
        x+=cint(n[i])*c;
    if (ch=='X' || ch=='x')
        x+=10;
    else
        x+=cint(n[i]);
    if(x%11==0)
        printf("The ISBN number is correct.\n");
    else
        printf("The ISBN not number is correct.\n");
    return 0;
}
