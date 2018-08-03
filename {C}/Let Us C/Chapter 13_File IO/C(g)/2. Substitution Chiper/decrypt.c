#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

    //  0   1   2   3...........125 126 127
    //  ↕   ↕   ↕   ↕...........↕   ↕   ↕
    //  255 254 253 252.........130 129 128

int main()
{
    FILE *fp;
    char c;
    fp=fopen("file_C(g)_2_t.txt","r");
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
            putch(255-c);
    }
    fclose(fp);
    return 0;
}
