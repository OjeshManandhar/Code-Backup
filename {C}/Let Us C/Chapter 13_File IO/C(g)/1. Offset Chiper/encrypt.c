#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

	//Offset by 128

int main()
{
    FILE *fs,*ft;
    char c;
    fs=fopen("file_C(g)_1_s.txt","r");
    if (fs==NULL)
    {
        perror("Can't open source");
        exit(EXIT_FAILURE);
    }
    ft=fopen("file_C(g)_1_t.txt","w");
    if (ft==NULL)
    {
        perror("Can't open target");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        c=fgetc(fs);
        if (c==EOF)
            break;
        else
            fputc(c+128,ft);
    }
    fclose(fs);
    fclose(ft);
    return 0;
}
