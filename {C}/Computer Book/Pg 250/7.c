#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct test
    {
        int no;
        char *text;
    }*data,*x;
    int n,i,l;
    char ch[50];
    printf("Enter the number of data to be entered: ");
    scanf("%d",&n);
    data=(struct test *)malloc(n*sizeof(struct test));
    for (i=0;i<n;i++)
    {
        x=&data[i];
        printf("\nEnter the number to be stored in data no.%d: ",i+1);
        scanf("%d",&x->no);
        fflush(stdin);
        printf("Enter a text to be stored in data no.%d: ",i+1);
        gets(ch);
        l=strlen(ch)+1;
        x->text=(char *)malloc(l*sizeof(char));
        strcpy(x->text,ch);
    }
    printf("\nThe data(s) you have entered is/are:\n");
    printf("No.\tText\n");
    for (i=0;i<n;i++)
    {
        x=&data[i];
        printf("%d\t%s\n",(*x).no,(*x).text);
    }
    return 0;
}
