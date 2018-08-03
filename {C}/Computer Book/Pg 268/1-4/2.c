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
    int flag=0;
    fp=fopen("Student.dat","rb");
    if (fp==NULL)
    {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }
    while (fread(&data.roll,sizeof(int),1,fp)==1)
    {
        if (flag==0)
            printf("Roll\t%-30s\tClass\tSection\t Total\n","Name");
        flag=1;
        fread(&data.size,sizeof(int),1,fp);
        data.name=(char *)malloc(data.size*sizeof(char));
        //fread(data.name,data.size*sizeof(char),1,fp);
        fread(data.name,sizeof(char),data.size,fp);
        fread(&data.grade,sizeof(int),1,fp);
        fread(&data.section,sizeof(char),1,fp);
        fread(&data.total,sizeof(float),1,fp);
        printf("%-4d\t%-30s\t%-5d\t%-7c\t %.2f\n",data.roll,data.name,data.grade,data.section,data.total);
    }
	if (flag==0)
		puts("NO DATA FOUND");
    fclose(fp);
    return 0;
}
