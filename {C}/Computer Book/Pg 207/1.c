#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *fn[10],*ln[10],n[50];
    int a[10],i;
    printf("Enter First name, Last name and Age of 10 different students.\n\n");
    for (i=0;i<3;i++)
    {
        fflush(stdin);
        printf("Enter First name of student no.%d: ",i+1);
        gets(n);
        fn[i]=(char *)malloc(strlen(n)+1);
        strcpy(fn[i],n);
        printf("Enter Last name of student no.%d: ",i+1);
        gets(n);
        ln[i]=(char *)malloc(strlen(n)+1);
        strcpy(ln[i],n);
        printf("Enter Age of student no.%d: ",i+1);
        scanf("%d",&a[i]);
        printf("\n");
    }
    printf("\n\nFirst Name\tLast Name\tAge\n");
    for (i=0;i<3;i++)
    {
        if (strlen(fn[i])<=9)
            printf("%s\t\t",fn[i]);
        else if (strlen(fn[i])<12)
            printf("%s\t",fn[i]);
        if (strlen(ln[i])<=9)
            printf("%s\t\t",ln[i]);
        else if (strlen(ln[i])<12)
            printf("%s\t",ln[i]);
        printf("%d\n",a[i]);
    }
    return 0;
}
