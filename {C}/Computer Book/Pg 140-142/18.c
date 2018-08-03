#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c,d,t,m;
    printf("Enter marks in English, Nepali, Account and Computer Science [SEPERATED BY A TAB]:");
    scanf("%f%f%f%f",&a,&b,&c,&d);
    t=a+b+c+d;
    m=t/4.0;
    printf("\nWith Total Marks and Average as %.2f and %.2f respectively,",t,a);
    if (m>=80)
        printf("the grade acquired is A.\n");
    else if (m>=70)
        printf("the grade acquired is B.\n");
    else if (m>=60)
        printf("the grade acquired is C.\n");
    else if (m>=50)
        printf("the grade acquired is D.\n");
    else
        printf("the grade acquired is E.\n");
    return 0;
}
