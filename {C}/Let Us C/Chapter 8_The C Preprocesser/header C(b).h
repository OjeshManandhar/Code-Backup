#define SMALL(ch) {\
                    if (ch>=97 && ch<=122)\
                        printf("\nThe letter is SMALL CASE.\n");\
                    else\
                        printf("\nThe letter is NOT a SMALL CASE.\n");\
                  }

#define UPPER(ch) {\
                    if (ch>=65 && ch<=90)\
                        printf("\nThe letter is UPPER CASE.\n");\
                    else\
                        printf("\nThe letter is NOT a UPPER CASE.\n");\
                  }

#define ALPHABET(ch) {\
                        if ((ch>=65 && ch<=90) || (ch>=97 && ch<=122))\
                            printf("\nThe character is ALPHABET.\n");\
                        else\
                            printf("\nThe character is NOT a ALPHABET.\n");\
                     }

#define CHECK(a,b) {\
                        if (a>b)\
                            printf("\n%.2f is greater than %.2f.\n",a,b);\
                        else if (b>a)\
                            printf("\n%.2f is greater than %.2f.\n",b,a);\
                        else\
                            printf("\nBoth area EQUAL.\n");\
                   }