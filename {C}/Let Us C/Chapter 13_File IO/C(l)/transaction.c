#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

struct student
{
    int roll;
    int size;
    char *name;
}*data;

struct transaction
{
    int roll;
    int size;
    char *name;
    char type;
}*trans;

int compare(const void *elem1, const void *elem2)
{
    struct transaction *x=(struct transaction *)elem1;
    struct transaction *y=(struct transaction *)elem2;

    return (x->roll - y->roll);
}

char getkey()
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

void del_record(struct transaction *arr,int *no,const int loc)
{
    int i,j,n=*no,size;
    struct transaction *temp;
    size=sizeof(struct transaction);
    temp=(struct transaction *)malloc((n-1)*size);
    for (i=0,j=0;i<n;i++)
        if (i!=loc)
        {
            temp[j]=arr[i];
            j++;
        }
    free(arr);
    n--;
    arr=(struct transaction *)malloc(n*size);
    for (i=0;i<n;i++)
        arr[i]=temp[i];
    free(temp);
    *no=n;
}

int main()
{
    FILE *fp;
    int i,n=0,total=0,flag=0,x;
    char c,ch[31];
    fp=fopen("master.dat","rb");
    if (fp==NULL)
    {
        perror("Can't open master.dat");
        exit(EXIT_FAILURE);
    }
    while (fread(&x,sizeof(int),1,fp)==1)
    {
        flag=1;
        total++;
        i=total-1;
        data=(struct student *)realloc(data,total*sizeof(struct student));
        data[i].roll=x;
        fread(&data[i].size,sizeof(int),1,fp);
        data[i].name=(char *)malloc(data[i].size*sizeof(char));
        fread(data[i].name,data[i].size*sizeof(char),1,fp);
    }
    if (flag==0)
    {
        puts("NO DATA FOUND.\nProgram terminated.");
        fclose(fp);
        exit(EXIT_SUCCESS);
    }
    else
    {
        puts("Data(s) in the master.dat file:");
        puts("Roll Name");
        for (i=0;i<total;i++)
            printf(" %-3.2d %s\n",data[i].roll,data[i].name);
        printf("\nPress Esc to exit or any other key to continue....");
        c=getkey();
        if (c==27)
        {
            free(data);
            fclose(fp);
            exit(EXIT_SUCCESS);
        }
        else
            system("cls");
    }
    fclose(fp);

    fp=fopen("transaction.dat","rb+");
    if (fp==NULL)
    {
        fp=fopen("transaction.dat","ab+");
        if (fp==NULL)
        {
            perror("Can't open transaction.dat");
            exit(EXIT_FAILURE);
        }
    }
    flag=0;
    n=1;
    i=n-1;
    trans=(struct transaction *)realloc(trans,n*sizeof(struct transaction));
    while (fread(&trans[i].roll,sizeof(int),1,fp)==1)
    {
        flag=1;
        fread(&trans[i].size,sizeof(int),1,fp);
        trans[i].name=(char *)malloc(trans[i].size*sizeof(char));
        fread(trans[i].name,trans[i].size*sizeof(char),1,fp);
        fread(&trans[i].type,sizeof(char),1,fp);
        n++;
        trans=(struct transaction *)realloc(trans,n*sizeof(struct transaction));
        i=n-1;
    }
    n--;
    if (flag==1)
    {
        puts("Data(s) which are already in the transaction.dat file:");
        printf("Roll %-30s Type\n","Name");
        for (i=0;i<n;i++)
            printf(" %-3.2d %-30s %c\n",trans[i].roll,trans[i].name,toupper(trans[i].type));
        printf("\nPress Esc to exit or any other key to continue....");
        c=getkey();
        if (c==27)
        {
            free(data);
            free(trans);
            fclose(fp);
            exit(EXIT_SUCCESS);
        }
        fclose(fp);
        remove("transaction.dat");
        fp=fopen("transaction.dat","wb+");
        system("cls");
    }
    do
    {
        flag=0;
        n++;
        i=n-1;
        trans=(struct transaction *)realloc(trans,n*sizeof(struct transaction));
        printf("Enter the ROLL NO. the student: ");
        scanf("%d",&trans[i].roll);
        for (x=0;x<i;x++)
            if (trans[x].roll==trans[i].roll)
            {
                flag=1;
                puts("\tREQUEST DENIED: Data is already present.");
                puts("Data Information:");
                printf("Roll = %-3.2d \t Name = %s \t Type = %c\n",trans[x].roll,trans[x].name,toupper(trans[x].type));
                do
                {
                    printf("DELETE that data [Y/N]: ");
                    fflush(stdin);
                    c=getchar();
                }while (c!='Y' && c!='y' && c!='N' && c!='n');
                if (c=='y' || c=='Y')
                {
                    del_record(trans,&n,x);      //position 'x'ko data delete garna|
                    del_record(trans,&n,n-1);    //position 'i'ko (last data) data delete garna|
                }
                else
                    n--;
                break;
            }
        if (flag==0)
            do
            {
                printf("Enter the TYPE of the transaction [A/D]: ");
                fflush(stdin);
                trans[i].type=getchar();
            }while (trans[i].type!='A' && trans[i].type!='D' && trans[i].type!='a' && trans[i].type!='d');
        for (x=0;x<total;x++)
            if (data[x].roll==trans[i].roll)
            {
                flag=1;
                break;
            }
        if ((trans[i].type=='a' || trans[i].type=='A') && flag==1)
        {
            puts("\tREQUEST DENIED: Data is already present.");
            n--;
        }
        else if ((trans[i].type=='a' || trans[i].type=='A') && flag==0)
        {
            printf("Enter name of the student [max 30 characters]: ");
            fflush(stdin);
            gets(ch);
            trans[i].size=strlen(ch)+1;
            trans[i].name=(char *)malloc(trans[i].size*sizeof(char));
            strcpy(trans[i].name,ch);
        }
        else if ((trans[i].type=='d' || trans[i].type=='D') && flag==0)
        {
            puts("\tREQUEST DENIED: Data is not present.");
            n--;
        }
        else if ((trans[i].type=='d' || trans[i].type=='D') && flag==1)
        {
            trans[i].size=data[x].size;
            trans[i].name=(char *)malloc(trans[i].size*sizeof(char));
            strcpy(trans[i].name,data[x].name);
        }
        printf("\nAdd another record [Y/N]: ");
        fflush(stdin);
        c=getchar();
        printf("\n");
    }while (c=='Y' || c=='y');
    printf("All data(s) has been entered. Press any key...");
    getch();
    system("cls");
    if (n==0)
        puts("NO DATA FOUND");
    else
    {
        puts("Data(s) which are already in file as well as newly entered data(s):\nDeleted data(s) are not shown.");
        printf("Roll %-30s Type\n","Name");
        for (i=0;i<n;i++)
           printf(" %-3.2d %-30s %c\n",trans[i].roll,trans[i].name,toupper(trans[i].type));
        qsort(trans,n,sizeof(struct transaction),compare);
        puts("\nThe data(s) will be STORED in ascending order of roll as:");
        printf("Roll %-30s Type\n","Name");
        for (i=0;i<n;i++)
        {
            printf(" %-3.2d %-30s %c\n",trans[i].roll,trans[i].name,toupper(trans[i].type));
            fwrite(&trans[i].roll,sizeof(int),1,fp);
            fwrite(&trans[i].size,sizeof(int),1,fp);
            fwrite(trans[i].name,sizeof(char),trans[i].size,fp);
            fwrite(&trans[i].type,sizeof(char),1,fp);
        }
    }
    free(data);
    free(trans);
    fclose(fp);
    return 0;
}
