#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct student
{
    int roll;
    int size;
    char *name;
}*data,*temp;

/*
int compare(const struct student *elem1, const struct student *elem2)
{
    return (elem1->roll - elem2->roll);
}
*/

int compare(const void *elem1, const void *elem2)
{
    struct student *x=(struct student *)elem1;
    struct student *y=(struct student *)elem2;

    return (x->roll - y->roll);
}

int getkey()
{
    int ch;
    ch=getch();
    if (ch==224)
    {
        ch=getch();
        return ch;
    }
    return ch;
}

void del_record(void *arr,int *no,const int loc)
{
    int i,j,n=*no,size;
    size=sizeof(struct student);
    struct student *data,*temp;
    data=(struct student *)arr;
    temp=(struct student *)malloc((n-1)*size);
    for (i=0,j=0;i<n;i++)
        if (i!=loc)
        {
            temp[j]=data[i];
            j++;
        }
    free(data);
    n--;
    data=(struct student *)malloc(n*size);
    for (i=0;i<n;i++)
        data[i]=temp[i];
    free(temp);
    *no=n;
}

int main()
{
    FILE *fp;
    int i,n=0,x,flag=0;
    char c,ch[31];
    fp=fopen("master.dat","rb+");
    if (fp==NULL)
    {
        fp=fopen("master.dat","ab+");
        if (fp==NULL)
        {
            perror("Can't open file");
            exit(EXIT_FAILURE);
        }
    }
    while (fread(&x,sizeof(int),1,fp)==1)
    {
        flag=1;
        n++;
        i=n-1;
        data=(struct student *)realloc(data,n*sizeof(struct student));
        data[i].roll=x;
        fread(&data[i].size,sizeof(int),1,fp);
        data[i].name=(char *)malloc(data[i].size*sizeof(char));
        fread(data[i].name,data[i].size*sizeof(char),1,fp);
    }
    if (flag==1)
    {
        puts("Data(s) which are already in file:");
        puts("Roll Name");
        for (i=0;i<n;i++)
            printf(" %-3.2d %s\n",data[i].roll,data[i].name);
        printf("\nPress Esc to exit or any other key to continue....");
        c=getkey();
        if (c==27)
        {
            free(data);
            fclose(fp);
            exit(EXIT_SUCCESS);
        }
        fclose(fp);
        remove("master.dat");
        fp=fopen("master.dat","wb+");
        system("cls");
    }
    do
    {
        flag=0;
        n++;
        i=n-1;
        data=(struct student *)realloc(data,n*sizeof(struct student));
        printf("Enter the ROLL NO. of the student: ");
        scanf("%d",&data[i].roll);
        for (x=0;x<i;x++)
            if (data[x].roll==data[i].roll)
            {
                flag=1;
                puts("\tREQUEST DENIED: Data is already present.");
                puts("Data Information:");
                printf("Roll = %-3.2d \t Name = %s\n",data[x].roll,data[x].name);
                do
                {
                    printf("DELETE that data [Y/N]: ");
                    fflush(stdin);
                    c=getchar();
                }while (c!='Y' && c!='y' && c!='N' && c!='n');
                if (c=='y' || c=='Y')
                {
                    del_record(data,&n,x);      //position 'x'ko data delete garna|
                    del_record(data,&n,n-1);    //position 'i'ko (last data) data delete garna|
                }
                else
                    n--;
                break;
            }
        if (flag==0)
        {
            do
            {
                printf("Enter the NAME of the student [MAX 30 CHARACTERS]: ");
                fflush(stdin);
                gets(ch);
                data[i].size=strlen(ch)+1;
            }while(data[i].size>31);
            data[i].name=(char *)malloc(data[i].size*sizeof(char));
            strcpy(data[i].name,ch);
        }
        printf("\nAdd another record [Y/N]: ");
        fflush(stdin);
        c=getchar();
        printf("\n");
    }while(c=='y' || c=='Y');
    printf("All data(s) has been entered. Press any key...");
    getch();
    system("cls");
    if (n==0)
        puts("NO DATA FOUND");
    else
    {
        puts("Data(s) which are already in file as well as newly entered data(s):\nDeleted data(s) are not shown.");
        puts("Roll Name");
        for (i=0;i<n;i++)
            printf(" %-3.2d %s\n",data[i].roll,data[i].name);
        qsort(data,n,sizeof(struct student),compare);
        puts("\nThe data(s) will be STORED in ascending order of roll as:");
        puts("Roll Name");
        for (i=0;i<n;i++)
        {
            printf(" %-3.2d %s\n",data[i].roll,data[i].name);
            fwrite(&data[i].roll,sizeof(int),1,fp);
            fwrite(&data[i].size,sizeof(int),1,fp);
            fwrite(data[i].name,data[i].size*sizeof(char),1,fp);
        }
    }
	free(data);
    fclose(fp);
    return 0;
}
