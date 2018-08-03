#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

	//  0   1   2   3...........125 126 127
    //  ↕   ↕   ↕   ↕...........↕   ↕   ↕
    //  255 254 253 252.........130 129 128

int main()
{
    FILE *fs,*ft;
    char c;
    fs=fopen("file_C(g)_2_s.txt","r");
    if (fs==NULL)
    {
        perror("Can't open source");
        exit(EXIT_FAILURE);
    }
    ft=fopen("file_C(g)_2_t.txt","w");
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
            fputc(255-c,ft);
    }
    fclose(fs);
    fclose(ft);
    return 0;
}
