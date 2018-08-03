#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int i,no_digit;
    long int n=0;
    char ch;

    cout << "Enter a number: ";
    for (i=1;i<=6;i++)
    {
        ch=getche();
        if (ch == '\r')
            break;
        n = n * 10 + (ch - 48);
    }

    cout << endl << "Number is: " << n << endl;

    return 0;
}
