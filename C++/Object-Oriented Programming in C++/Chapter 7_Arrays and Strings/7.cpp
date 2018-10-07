#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

long double mstold(string data)
{
    int i;
    char ch;
    string temp;

    for (i = 0; i < static_cast<int>(data.length()); i++)
    {
        ch = data.at(i);

        if  ((ch >= '0' && ch <= '9') || ch == '.')
            temp += ch;
    }

    return stold(temp);
    //set flag [--std=c++11] from settings/compiler/global compiler settings/compiler flags to use stold
}

int main()
{
    string data;

    cout << "Enter amount: ";
    getline(cin, data);

    cout << setiosflags(ios::fixed) //fixed (not exponential)
         << setiosflags(ios::showpoint)
         << endl << "Amount: " << mstold(data) << endl;

    return 0;
}
