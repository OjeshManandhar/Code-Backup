#include <iostream>
#include <string>

using namespace std;

class bMoney
{
private:
    long double money;

public:
    bMoney(): money(0)
    {}

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

    void getmoney()
    {
        string temp;

        cout << "Enter amount: ";
        fflush(stdin);
        getline(cin, temp);

        money = mstold(temp);
    }

    void putmoney()
    {
        cout << endl << "Amount: " << ldtoms(money) << endl;
    }

    void madd(bMoney m1, bMoney m2)
    {
        money = m1.money + m2. money;
    }
};

int main()
{
    char ch;
    bMoney a, b, sum;

    do
    {
        a.getmoney();
        b.getmoney();

        sum.madd(a, b);

        sum.putmoney();

        cout << endl << "Add another amounts [Y/N]: ";
        cin >> ch;
        cout << endl;
    }while (ch == 'y' || ch == 'Y');

    return 0;
}
