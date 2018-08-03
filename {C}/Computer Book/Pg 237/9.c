#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct system
    {
        char *mou;
        char *mon;
        char *cpu;
        char *memo;
    }*data=NULL;
    int n,i,l;
    char ch[50];
    printf("How many data do you want to enter: ");
    scanf("%d",&n);
    data=(struct system *)malloc(n*sizeof(struct system));
    for (i=0;i<n;i++)
    {
        fflush(stdin);
        printf("\nEnter data on MOUSE of data no.%d: ",i+1);
        gets(ch);
        l=strlen(ch)+1;
        data[i].mou=(char *)malloc(l*sizeof(char));
        strcpy(data[i].mou,ch);
        fflush(stdin);
        printf("Enter data on MONITOR of data no.%d: ",i+1);
        gets(ch);
        l=strlen(ch)+1;
        data[i].mon=(char *)malloc(l*sizeof(char));
        strcpy(data[i].mon,ch);
        fflush(stdin);
        printf("Enter data on CPU of data no.%d: ",i+1);
        gets(ch);
        l=strlen(ch)+1;
        data[i].cpu=(char *)malloc(l*sizeof(char));
        strcpy(data[i].cpu,ch);
        fflush(stdin);
        printf("Enter data on MEMORY of data no.%d: ",i+1);
        gets(ch);
        l=strlen(ch)+1;
        data[i].memo=(char *)malloc(l*sizeof(char));
        strcpy(data[i].memo,ch);
    }
    printf("\nAll data(s) have been entered. Press any key.");
    getch();
    system("cls");
    printf("Mouse\tMonitor\tCPU\tMemory\n");
    for (i=0;i<n;i++)
        printf("%s\t%s\t%s\t%s\n",data[i].mou,data[i].mon,data[i].cpu,data[i].memo);
    return 0;
}
