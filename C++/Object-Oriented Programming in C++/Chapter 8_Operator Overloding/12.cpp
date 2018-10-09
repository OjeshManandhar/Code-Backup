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

    bMoney(const long double d): money(d)
    {}

    long double get_money() const
    {
        return money;
    }

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

    void getbMoney()
    {
        string temp;

        fflush(stdin);
        getline(cin, temp);

        money = mstold(temp);
    }

    void putbMoney()
    {
        cout << ldtoms(money) << endl;
    }
};

class sterling
{
private:
    long int pounds;
    int shillings, pence;

public:
    sterling(long int pnd = 0, int str = 0, int pen = 0): pounds(pnd), shillings(str), pence(pen)
    {}

    sterling(const bMoney b)
    {
        long double temp_pounds, temp_shilling;

        temp_pounds = b.get_money()/50.0;
        pounds = static_cast<long int>(temp_pounds);
        temp_shilling = (temp_pounds - pounds)*20;
        shillings = static_cast<long int>(temp_shilling);
        pence = (temp_shilling - shillings)*12;
    }

    operator bMoney() const
    {
        long double temp_pounds;

        temp_pounds = pounds + shillings/20.0 + pence/(20.0*12.0);

        return bMoney(temp_pounds*50);
    }

    void getSterling()
    {
        char dummy;

        cout << "Enter amount: \x9C";
        cin >> pounds >> dummy >> shillings >> dummy >> pence;
    }

    void putSterling() const
    {
        cout << '\x9c' << pounds << '.' << shillings << '.' << pence << endl;
    }
};

int main()
{
    int choice;

    cout << "Choose an option:" << endl
         << "1. sterling to bMoney" << endl
         << "2. bMoney to sterling" << endl
         << "Enter your choice: ";
    cin >> choice;

    cout << endl;
    switch (choice)
    {
    case 1:
        {
            sterling str;
            bMoney bm;

            cout << "Enter amount in sterling:" << endl;
            str.getSterling();

            bm = str;

            cout << endl << "Equivalent bMoney = ";
            bm.putbMoney();

        }
        break;
    case 2:
        {
            bMoney bm;

            cout << "Enter amount in bMoney: $";
            bm.getbMoney();

            sterling str = bm;

            cout << endl << "Equivalent sterling = ";
            str.putSterling();
        }
        break;
    default:
        cout << "Wrong input." << endl;
    }

    return 0;
}
