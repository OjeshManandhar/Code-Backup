#define MEAN(a,b,m) (m=(a+b)/2.0)

#define ABS(a) if (a>0)\
                    printf("\nThe absolute value of %.2f is: %.2f.\n",a,a);\
               else\
                    printf("\nThe absolute value of %.2f is: %.2f.\n",a,(a*-1));

#define CONVERT(ch) if (ch>=65 && ch<=90)\
                        printf("\nSMALL CASE of %c is: %c.\n",ch,ch+32);\
                    else\
                        printf("\nWRONG INPUT.\n");\

#define CHECK(a,b) if (a>b)\
                        printf("\n%.2f is greater than %.2f.\n",a,b);\
                   else if (b>a)\
                        printf("\n%.2f is greater than %.2f.\n",b,a);\
                   else\
                        printf("\nBoth area EQUAL.\n");
