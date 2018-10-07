#include <iostream>
#include <string>

using namespace std;

string ldtoms(long double data)
{
    int i, flag, n, write_flag;
    char ch;
    string ans, temp;

    temp = to_string(data);
    //enable compiler flag -std=c++11

    flag = 0;
    write_flag = 0;
    n = 0;
    for (i = temp.length() - 1; i >= 0; i--)
    {
        ch = temp.at(i);

        if (ch != '0' && write_flag == 0)
            write_flag = 1;

        if (write_flag == 0)
            continue;

        ans = ch + ans;

        if (flag == 1)
        {
            n++;

            if (n%3 == 0)
                ans = ',' + ans;
        }

        if (ch == '.')
            flag = 1;
    }

    if (ans.at(ans.length() - 1) == '.')
        ans.erase(ans.length() - 1, 1);

    if (ans.at(0) == ',')
        ans.at(0) = '$';
    else
        ans = '$' + ans;

    return ans;
}

int main()
{
    long double data;

    cout << "Enter amount: ";
    cin >> data;

    if (data > 9999999999999990.00)
        cout << "Cannot convert." << endl;
    else
        cout << endl << "Amount: " << ldtoms(data) << endl;

    return 0;
}
