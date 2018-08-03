#include <stdio.h>
#include <stdlib.h>

int main()
{
    float bs,gs;
    printf("Enter Ramesh's Basic Salary: Rs.");
    scanf("%f",&bs);
    gs=(bs*40/100)+(bs*20/100)+bs;
    printf("\nGross Salary of Ramesh is: Rs.%.2f.\n",gs);
    return 0;
}
