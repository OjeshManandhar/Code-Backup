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

    explicit bMoney(const long double d): money(d)
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

        fflush(stdin);
        getline(cin, temp);

        money = mstold(temp);
    }

    void putmoney()
    {
        cout << ldtoms(money) << endl;
    }

    bMoney operator +(const bMoney b) const
    {
        return bMoney(money + b.money);
    }

    bMoney operator -(const bMoney b) const
    {
        return bMoney(money - b.money);
    }

    bMoney operator *(const long double mul) const
    {
        return bMoney(money * mul);
    }

    long double operator /(const bMoney b) const
    {
        return money/b.money;
    }

    bMoney operator /(const long double div) const
    {
        return bMoney(money/div);
    }
};

int main()
{
    bMoney total, price;
    long double no_widgets;
    char choice;

    do
    {
        cout << "Enter total price: ";
        total.getmoney();
        cout << "Enter price per widget: ";
        price.getmoney();
        cout << "Enter no. of widgets: ";
        cin >> no_widgets;

        cout << endl << "Total price + price per widget: ";
        (total + price).putmoney();
        cout << "Total price - price per widget: ";
        (total - price).putmoney();
        cout << "Price per widget * no. of widgets: ";
        (price * no_widgets).putmoney();
        cout << "Total price / price per widget: ";
        cout << total/price << endl;
        cout << "Total price / no. of widget: ";
        (total/no_widgets).putmoney();

        cout << endl << "Continue [Y/N]: ";
        cin >> choice;
        if (choice == 'y')
            choice = 'Y';
        cout << endl;
    }while (choice == 'Y');

    return 0;
}
