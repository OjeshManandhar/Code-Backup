#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

	//Offset by 128

int main()
{
    FILE *fp;
    char c;
    fp=fopen("file_C(g)_1_t.txt","r");
    if (fp==NULL)
    {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        c=fgetc(fp);
        if (c==EOF)
            break;
        else
            putch(c-128);
    }
    printf("\n");
    fclose(fp);
    return 0;
}
