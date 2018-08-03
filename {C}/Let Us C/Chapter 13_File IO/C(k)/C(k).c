#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct student
{
    int size;
    char *name;
}*data;

int main()
{
    FILE *fp;
    int n=0,s,i,c,loc,flag;
    fp=fopen("file_C(k).dat","rb");
    if (fp==NULL)
    {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }
    while(fread(&s,sizeof(int),1,fp)==1)
    {
        n++;
        i=n-1;
        data=realloc(data,n*sizeof(*data));
        data[i].size=s;
        data[i].name=malloc(data[i].size*sizeof*data[i].name);
        fread(data[i].name,data[i].size*sizeof(*data[i].name),1,fp);
    }
    while (1)
    {
        system("cls");
        puts("\tMAIN MENU");
        puts("1. Display nth name.");
        puts("2. Display names starting with 'S'.");
        puts("3. Exit.");
        printf("Enter your choice: ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            system("cls");
            puts("\t\tDISPLAYING nth NAME\n");
            printf("Enter the value of n: ");
            scanf("%d",&loc);
            if (loc>n)
                puts("NO DATA FOUND");
            else
                printf("The name int he location %d is %s.\n",loc,data[loc-1].name);
            printf("\nPress any key to go back to main menu....");
            getch();
            break;
        case 2:
            flag=0;
            system("cls");
            puts("\t\tDISPLAYING ALL NAMES STARTING WITH 'S'\n");
            for (i=0;i<n;i++)
                if (data[i].name[0]=='S' || data[i].name[0]=='s')
                {
                    if (flag==0)
                        printf("Location Name\n");
                    flag=1;
                    printf("   %-5.2d %s\n",i,data[i].name);
                }
            if (flag==0)
                puts("NO DATA FOUND");
            printf("\nPress any key to go back to main menu....");
            getch();
            break;
        case 3:
            system("cls");
            printf("PROGTAM TERMINATED. Press any key to exit....");
            getch();
            exit(EXIT_SUCCESS);
        }
    }
	free(data);
    fclose(fp);
    return 0;
}
