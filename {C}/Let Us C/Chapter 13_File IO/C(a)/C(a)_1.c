#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char c;
    int n=1,flag=1;
    fp=fopen("file_C(a).txt","r");
    printf("%-8s Data","Line No.");
    while (1)
    {
        if (flag==1)
        {
            printf("\n   %-6d",n);
            flag=0;
        }
        c=fgetc(fp);
        if (c=='\n')
        {
            n++;
            flag=1;
        }
        else
            printf("%c",c);
        if (c==EOF)
            break;
    }
    printf("\n");
	fclose(fp);
    return 0;
}
