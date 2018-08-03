#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <upper.h>

struct student
{
    int grade,roll;
    int size;
    char *name;
    float phy,chem,math,eng,nep,comp;
}data;

int main()
{
    FILE *fp;
    char c,ch[31];
    fp=fopen("file_5.dat","ab");
    if (fp==NULL)
    {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }
    do
    {
        do
        {
            printf("Enter the CLASS of the student [11 - 12]: ");
            scanf("%d",&data.grade);
        }while (data.grade<11 || data.grade>12);
        do
        {
            printf("Enter the ROLL of the student [1 - 50]: ");
            scanf("%d",&data.roll);
        }while (data.roll<1 || data.roll>50);
        do
        {
            printf("Enter the NAME of the student [MAX 30 CHARACTERS]: ");
            fflush(stdin);
            gets(ch);
            data.size=strlen(ch)+1;
        }while (data.size>31);
        data.name=(char *)malloc(data.size*sizeof(char));
        strcpy(data.name,ch);
        do
        {
            printf("Enter marks in PHYSICS: ");
            scanf("%f",&data.phy);
        }while (data.phy>100);
        do
        {
            printf("Enter marks in CHEMISTRY: ");
            scanf("%f",&data.chem);
        }while (data.chem>100);
        do
        {
            printf("Enter marks in MATH: ");
            scanf("%f",&data.math);
        }while (data.math>100);
        do
        {
            printf("Enter marks in ENGLISH: ");
            scanf("%f",&data.eng);
        }while (data.eng>100);
        do
        {
            printf("Enter marks in NEPALI: ");
            scanf("%f",&data.nep);
        }while (data.nep>100);
        do
        {
            printf("Enter marks in COMPUTER: ");
            scanf("%f",&data.comp);
        }while (data.comp>100);

        fwrite(&data.grade,sizeof(int),1,fp);
        fwrite(&data.roll,sizeof(int),1,fp);
        fwrite(&data.size,sizeof(int),1,fp);
        fwrite(data.name,data.size*sizeof(char),1,fp);
        fwrite(&data.phy,sizeof(float),1,fp);
        fwrite(&data.chem,sizeof(float),1,fp);
        fwrite(&data.math,sizeof(float),1,fp);
        fwrite(&data.eng,sizeof(float),1,fp);
        fwrite(&data.nep,sizeof(float),1,fp);
        fwrite(&data.comp,sizeof(float),1,fp);
        printf("\n");
        do
        {
            printf("Enter another record [Y/N]: ");
            fflush(stdin);
            c=cupr(getchar());
        }while (c!='Y' && c!='N');
        printf("\n");
    }while (c=='Y');
    puts("All data(s) have been entered.");
    printf("Press any key to continue...");
    getch();
    fclose(fp);
    return 0;
}
