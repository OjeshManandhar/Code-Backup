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
    FILE *fp,*ft;
    fp=fopen("Student.dat","rb");
    if (fp==NULL)
    {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }
    ft=fopen("temp.dat","wb");
    while (fread(&data.roll,sizeof(int),1,fp)==1)
    {
        fread(&data.size,sizeof(int),1,fp);
        data.name=(char *)malloc(data.size*sizeof(char));
        //fread(data.name,data.size*sizeof(char),1,fp);
        fread(data.name,sizeof(char),data.size,fp);
        fread(&data.grade,sizeof(int),1,fp);
        fread(&data.section,sizeof(char),1,fp);
        fread(&data.total,sizeof(float),1,fp);
        if (data.roll!=10)
        {
            fwrite(&data.roll,sizeof(int),1,ft);
            fwrite(&data.size,sizeof(int),1,ft);
            //fwrite(data.name,data.size*sizeof(char),1,ft);
            fwrite(data.name,sizeof(char),data.size,ft);
            fwrite(&data.grade,sizeof(int),1,ft);
            fwrite(&data.section,sizeof(char),1,ft);
            fwrite(&data.total,sizeof(float),1,ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("Student.dat");
    rename("temp.dat","Student.dat");
    return 0;
}
