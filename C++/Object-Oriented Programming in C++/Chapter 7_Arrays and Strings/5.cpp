#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class fraction
{
private:
    int num, den;

public:
    fraction(): num(0), den(1)
    {}

    void lowterms()
    {
        int tnum, tden, gcd;

        tnum = abs(num);
        tden = abs(den);
        if (tden == 0)
        {
            cout << "Illegal fraction: division by 0";
            exit(EXIT_FAILURE);
        }
        else if (tnum == 0)
        {
            num = 0;
            den = 1;
            return;
        }

        while (tnum != 0)
        {
            if (tnum < tden)
                swap(tnum, tden);
            tnum = tnum - tden;
        }
        gcd = tden;
        num = num/gcd;
        den = den/gcd;
    }

    void manage_sign()
    {
        if (den < 0)
        {
            den *= -1;
            num *= -1;
        }
    }

    void input()
    {
        cout << "Enter numerator: ";
        cin >> num;
        cout << "Enter denominator: ";
        cin >> den;

        lowterms();
        manage_sign();
    }

    void output()
    {
        cout << num << '/' << den << endl;
    }

    fraction fadd(const fraction a)
    {
        fraction ans;

        ans.num = num * a.den + den * a.num;
        ans.den = den * a.den;

        ans.lowterms();
        ans.manage_sign();
        return ans;
    }

    fraction average(const int divisor)
    {
        fraction ans;

        ans.num = num;
        ans.den = den * divisor;

        ans.lowterms();
        ans.manage_sign();
        return ans;
    }
};

int main()
{
    fraction data[10], total;
    int i;
    char ch;

    i = 0;
    do
    {
        i++;

        data[i - 1].input();

        total = total.fadd(data[i - 1]);

        cout << endl << "Enter another fraction [Y/N]: ";
        cin >> ch;
        if (ch == 'y')
            ch = 'Y';
        cout << endl;
    }while (ch == 'Y');

    total = total.average(i);

    cout << "Average: ";
    total.output();

    return 0;
}
