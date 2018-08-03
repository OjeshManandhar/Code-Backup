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
    int flag=0;
    fp=fopen("file_5.dat","rb");
    if (fp==NULL)
    {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }
    while (fread(&data.grade,sizeof(int),1,fp)==1)
    {
        fread(&data.roll,sizeof(int),1,fp);
        fread(&data.size,sizeof(int),1,fp);
        data.name=(char *)malloc(data.size*sizeof(char));
        fread(data.name,data.size*sizeof(char),1,fp);
        fread(&data.phy,sizeof(float),1,fp);
        fread(&data.chem,sizeof(float),1,fp);
        fread(&data.math,sizeof(float),1,fp);
        fread(&data.eng,sizeof(float),1,fp);
        fread(&data.nep,sizeof(float),1,fp);
        fread(&data.comp,sizeof(float),1,fp);
        if (data.eng>80 && flag==0)
        {
            puts("List of students whose marks in ENGLISH is greater than 80 is:\n");
            printf("Grade Roll %-30s %-5s %-5s %-5s %-5s %-5s %-5s\n","Name","Phy","Chem","Maths","Eng","Nep","Comp");
            printf("%-5d %-4d %-30s %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f\n",data.grade,data.roll,data.name,data.phy,data.chem,data.math,data.eng,data.nep,data.comp);
            flag=1;
        }
        else if (data.eng>80)
            printf("%-5d %-4d %-30s %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f\n",data.grade,data.roll,data.name,data.phy,data.chem,data.math,data.eng,data.nep,data.comp);
    }
    if (flag==0)
        puts("NO DATA FOUND");
    fclose(fp);
    return 0;
}
