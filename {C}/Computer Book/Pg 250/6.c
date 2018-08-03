#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int swap(int *a,int *b)
{
    int x;
    x=*a;
    *a=*b;
    *b=x;
}

int main()
{
    int i,j,n,*age;
    do
    {
        printf("Enter the number of person whose age you want to swap [MAX=100]: ");
        scanf("%d",&n);
    }while (n<1 || n>100);
    age=(int *)malloc(n*sizeof(int));
    printf("\n");
    for (i=0;i<n;i++)
    {
        printf("Enter the age  of person no.%d: ",i+1);
        scanf("%d",&(*(age+i)));
    }
    for (i=0;i<n;i++)
        for (j=i;j<n;j++)
            if ((*(age+i))<(*(age+j)))  //if (age[i]<age[j])
                swap((age+i),(age+j));      //swap(&age[i],&age[j]);
    printf("\nThe list of age sorted in descending order is:\n");
    for (i=0;i<n;i++)
        printf("%d, ",*(age+i));
    printf("\n");
    return 0;
}
