#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <stdint.h>
#include <inttypes.h>

#define _BV(x) (1<<x)

int main()
{
    int i,n,flag=0,data[]={273,548,786,1096};
    struct student
    {
        char *year;
        char *stream;
        int room;
    }record;
    printf("Enter room no.: ");
    scanf("%d",&n);
    for (i=0;i<4;i++)
    {
        if ((data[i]&_BV(0))!=0)
            record.year="First year";
        else if ((data[i]&_BV(1))!=0)
            record.year="Second year";
        else if ((data[i]&_BV(2))!=0)
            record.year="Third year";
        else if ((data[i]&_BV(3))!=0)
            record.year="Fourth year";

        if ((data[i]&_BV(4))!=0)
            record.stream="Mechanical";
        else if ((data[i]&_BV(5))!=0)
            record.stream="Chemical";
        else if ((data[i]&_BV(6))!=0)
            record.stream="Electrical";
        else if ((data[i]&_BV(7))!=0)
            record.stream="IT";

        record.room=data[i]>>8;

        if (record.room==n)
        {
            flag=1;
            printf("\nStudent No.: %d\n",i+1);
            printf("Year: %s\n",record.year);
            printf("Stream: %s\n",record.stream);
        }
    }
    if (flag==0)
        puts("\nNO DATA FOUND.");
    return 0;
}
