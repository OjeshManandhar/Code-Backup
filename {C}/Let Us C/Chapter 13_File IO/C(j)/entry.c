#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main()
{
    FILE *fp;
    int age,type;
    char name[21],address[41],c;
    fp=fopen("file_C(j).txt","a+");
    if (fp==NULL)
    {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }
    do
    {
        printf("Enter the NAME of the donors [MAX 20 CHARACTERS]: ");
        fflush(stdin);
        gets(name);
        printf("Enter the ADDRESS of the donors [MAX 40 CHARACTERS]: ");
        fflush(stdin);
        gets(address);
        printf("Enter the AGE of the donor: ");
        scanf("%d",&age);
        do
        {
            printf("Enter the BLOOD TYPE of the donor [1/2/3/4]: ");
            scanf("%d",&type);
        }while (type<1 || type >4);
        fprintf(fp,"%-20s%-40s%.2d %d\n",name,address,age,type);
				//'age' ra 'type' ko bichma vayeko 'space' le duitalai xutauxa write huda|
        printf("\nEnter another record [Y/N]: ");
        fflush(stdin);
        c=getchar();
        printf("\n");
    }while (c=='y' || c=='Y');
    fclose(fp);
    return 0;
}
