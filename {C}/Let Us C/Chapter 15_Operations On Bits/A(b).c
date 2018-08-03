#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define _BV(x) (1<<(x))

int main()
{
    int *arr=NULL,i,n1,n2,n3,total=0,count_enda=0,count_uptb=0,count_reg=0;
    char c;
    do
    {
        total++;
        i=total-1;
        arr=(int *)realloc(arr,total*sizeof(int));
        arr[i]=0;
        printf("Enter the information of person %d:\n",i+1);
        puts("\nChoose CLASS:");
        puts("1. Upper Class.");
        puts("2. Middle Class.");
        puts("3. Lower Class.");
        printf("Enter CLASS: ");
        scanf("%d",&n1);
        arr[i]|=_BV(n1-1);
        puts("\nChoose LANGUAGE:");
        puts("1. English.");
        puts("2. Nepali.");
        puts("3. Regional.");
        printf("Enter LANGUAGE: ");
        scanf("%d",&n2);
        arr[i]|=_BV(n2+2);
        puts("\nChoose category of paper:");
        puts("1. Daily.");
        puts("2. Supplement.");
        puts("3. Tabloid.");
        printf("Enter CATEGORY: ");
        scanf("%d",&n3);
        arr[i]|=_BV(n3+5);
        if (n2==1 || n3==1)
            count_enda++;
        if (n2==3)
            count_reg++;
        if (n1==1 && n3==3)
            count_uptb++;
        printf("\n");
        do
        {
            printf("Add information of another person [Y/N]: ");
            fflush(stdin);
            c=getchar();
        }while (c!='Y' && c!='N' && c!='y' && c!='n');
        printf("\n");
    }while (c=='y' || c=='Y');
    puts("All information has been saved.");
    printf("Press any key to continue...");
    getch();
    system("cls");
    printf("Number of person who read English Daily is: %d\n",count_enda);
    printf("Number of Upper Class person who read Tabloid is: %d\n",count_uptb);
    printf("Number of Regional Language readers is: %d\n",count_reg);
    return 0;
}
