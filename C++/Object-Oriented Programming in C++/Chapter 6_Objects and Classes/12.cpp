#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>

using namespace std;

class fraction
{
private:
    int num, den;
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
public:
    fraction(int d = 1)
    {
        num = 1;
        den = d;
    }
    void setdata(int n = 1, int d = 1)
    {
        num = n;
        den = d;

        lowterms();
    }
    void output(int n = 5) const
    {
        cout << setw(n) << right << num << '/' << setw(3) << left << den;
    }
    fraction fmul(const fraction a) const
    {
        fraction ans;

        ans.num = num * a.num;
        ans.den = den * a.den;

        ans.lowterms();
        return ans;
    }
};

int main()
{
    int d, i, j;
    fraction a, b, ans;

    cout << "Enter denominator: ";
    cin >> d;

    cout << setw(5) << ' ';
    for (i = 1; i < d; i++)
    {
        b.setdata(i, d);
        b.output();
    }
    cout << endl;
    for (i = 0; i < 80; i++)
        cout << '-';

    for (i = 1; i < d; i++)
    {
        a.setdata(i, d);
        a.output(0);
        for (j = 1; j < d; j++)
        {
            b.setdata(j, d);
            ans = a.fmul(b);
            ans.output();
        }
        cout << endl;
    }

    system("pause");
    return 0;
}
