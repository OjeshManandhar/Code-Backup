#include <iostream>
#include <ctype.h>

using namespace std;

int main()
{
    char ch;

    cout << "Enter a letter: ";
    cin >> ch;

    cout << endl << islower(ch) << endl;
    return 0;
}
