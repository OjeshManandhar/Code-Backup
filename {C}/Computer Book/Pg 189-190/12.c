#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int p[5],i,len;
    char *name[5],*add[5],n[100];
    printf("Enter Name, Address and Phone number of 5 different students.\n\n");
    for (i=0;i<5;i++)
    {
        fflush(stdin);
        printf("Enter the Name of the student no.%d: ",i+1);
        gets(n);
        len=strlen(n);
        name[i]=(char *)malloc(len+1);
        strcpy(name[i],n);
        fflush(stdin);
        printf("Enter the Address of the student no.%d: ",i+1);
        gets(n);
        len=strlen(n);
        add[i]=(char *)malloc(len+1);
        strcpy(add[i],n);
        printf("Enter the Phone number of the student no.%d: ",i+1);
        scanf("%d",&p[i]);
        if (p[i]<=4200000 || p[i]>=6799999)
        {
            printf("\nWrong Entry.\nEnter the information of this student from beginning.\n");
            i--;
        }
        printf("\n");
    }
    printf("\nThe data you have entered is:\n");
    printf("S.N.\tName\t\tAddress\t\tPhone Number\n");
    for (i=0;i<5;i++)
    {
        printf("%d\t",i+1);
        if (strlen(name[i])>6)
            printf("%s\t",name[i]);
        else
            printf("%s\t\t",name[i]);
        if (strlen(add[i])>6)
            printf("%s\t%d\n",add[i],p[i]);
        else
            printf("%s\t\t%d\n",add[i],p[i]);
    }
    return 0;
}
