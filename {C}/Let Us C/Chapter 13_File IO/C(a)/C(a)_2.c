#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    int n=1;
    char c;
    fp=fopen("jpt.txt","r");
    if (fp==NULL)
    {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }
    printf("Line No. Data");
    printf("\n  %-6.2d ",n);
    while ((c=fgetc(fp))!=EOF)
    {
        if (c=='\n')
        {
            n++;
            printf("\n  %-6.2d ",n);
        }
        else
            putch(c);
    }
    fclose(fp);
    return 0;
}
