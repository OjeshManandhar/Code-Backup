#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[9][10][6]={
                            {" ### "," # "," ### "," ### ","   # ","#####","  ## ","#####"," ### "," ### "},
                            {"#   #","## ","#   #","#   #","  ## ","#    "," #   ","#   #","#   #","#   #"},
                            {"#   #"," # ","#   #","#   #","  ## ","#    ","#    ","    #","#   #","#   #"},
                            {"#   #"," # ","    #","    #"," # # ","#### ","#    ","   # ","#   #","#   #"},
                            {"#   #"," # ","   # ","  ## "," # # ","#   #","#### ","   # "," ### "," ####"},
                            {"#   #"," # ","  #  ","    #","#  # ","    #","#   #","   # ","#   #","    #"},
                            {"#   #"," # "," #   ","#   #","#####","    #","#   #","  #  ","#   #","    #"},
                            {"#   #"," # ","#    ","#   #","   # ","#   #","#   #","  #  ","#   #","   # "},
                            {" ### ","###","#####"," ### ","   # "," ### "," ### ","  #  "," ### "," ##  "}
                        },x[6];
    int i,j,l;
    do
    {
        system("cls");
        printf("Enter a 5-digit number: ");
        gets(x);
        l=strlen(x);
    }while(l!=5);
    printf("\n");
    for (i=0;i<9;i++)
    {
        for (j=0;j<5;j++)
            if (x[j]=='0')
                printf("%s  ",text[i][0]);
            else if (x[j]=='1')
                printf("%s  ",text[i][1]);
            else if (x[j]=='2')
                printf("%s  ",text[i][2]);
            else if (x[j]=='3')
                printf("%s  ",text[i][3]);
            else if (x[j]=='4')
                printf("%s  ",text[i][4]);
            else if (x[j]=='5')
                printf("%s  ",text[i][5]);
            else if (x[j]=='6')
                printf("%s  ",text[i][6]);
            else if (x[j]=='7')
                printf("%s  ",text[i][7]);
            else if (x[j]=='8')
                printf("%s  ",text[i][8]);
            else if (x[j]=='9')
                printf("%s  ",text[i][9]);
        printf("\n");
    }
    return 0;
}
