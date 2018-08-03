#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main()
{
    FILE *fp;
    int age,type;
    char name[21],address[41];
    fp=fopen("file_C(j).txt","r");
    if (fp==NULL)
    {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }
    puts("Records of the donor who are below the age of 25 and have blood type 2.\n");
    printf("%-20s %-40s Age Type\n","Name","Address");
    while (fgets(name,21,fp)!=NULL)
    {
        fgets(address,41,fp);
                //name ko 0,1,2....20 positionma data ra 21 positionma '/0' hunxa|
                //address ko 0,1,2....40 positionma data ra 41 positionma '/0' hunxa|
        fscanf(fp,"%d %d",&age,&type);
        fgetc(fp);
        if (age<25 && type==2)
            printf("%-20s %-40s %d  %d\n",name,address,age,type);
    }
    fclose(fp);
    return 0;
}
