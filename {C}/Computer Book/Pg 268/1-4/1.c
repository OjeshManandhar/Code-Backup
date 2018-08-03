#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <upper.h>

struct student
{
    int roll;
    int size;
    char *name;
    int grade;
    char section;
    float total;
}data;

int main()
{
    FILE *fp;
    char c,ch[31];
    fp=fopen("Student.dat","ab");
    if (fp==NULL)
    {
        perror("Can't open file")
        exit(EXIT_FAILURE);
    }
    do
    {
        printf("Enter the ROLL NUMBER of the student: ");
        scanf("%d",&data.roll);
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
            printf("Enter the CLASS of the student [1 - 10]: ");
            scanf("%d",&data.grade);
        }while (data.grade<1 || data.grade>10);
        do
        {
            printf("Enter the SECTION of the student [A - E]: ");
            fflush(stdin);
            data.section=getchar();
            data.section=cupr(data.section);
        }while (data.section<'A' || data.section>'E');
        do
        {
            printf("Enter TOTAL MARKS OBTAINED by the student [MAX 800]: ");
            scanf("%f",&data.total);
        }while (data.total>800);

        fwrite(&data.roll,sizeof(int),1,fp);
        fwrite(&data.size,sizeof(int),1,fp);
        //fwrite(data.name,data.size*sizeof(char),1,fp);
        fwrite(data.name,sizeof(char),data.size,fp);
        fwrite(&data.grade,sizeof(int),1,fp);
        fwrite(&data.section,sizeof(char),1,fp);
        fwrite(&data.total,sizeof(float),1,fp);

        printf("\n");
        do
        {
            printf("Add another record [Y/N]: ");
            fflush(stdin);
            c=getchar();
            c=cupr(c);
        }while (c!='Y' && c!='N');
        printf("\n");
    }while(c=='Y');
	fclose(fp);
    return 0;
}
