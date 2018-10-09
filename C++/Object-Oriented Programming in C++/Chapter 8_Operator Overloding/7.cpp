#include <iostream>
#include <stdlib.h>
#include <cmath>

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
    fraction(int n = 0, int d = 0)
    {
        num = n;
        den = d;
    }

    void input()
    {
        cout << "Enter numerator: ";
        cin >> num;
        cout << "Enter denominator: ";
        cin >> den;

        this->lowterms();
    }

    void output() const
    {
        cout << num << '/' << den << endl;
    }

    fraction operator +(const fraction a) const
    {
        fraction ans;

        ans.num = num * a.den + den * a.num;
        ans.den = den * a.den;

        ans.lowterms();
        return ans;
    }

    fraction operator -(const fraction a) const
    {
        fraction ans;

        ans.num = num * a.den - den * a.num;
        ans.den = den * a.den;

        ans.lowterms();
        return ans;
    }

    fraction operator *(const fraction a) const
    {
        fraction ans;

        ans.num = num * a.num;
        ans.den = den * a.den;

        ans.lowterms();
        return ans;
    }

    fraction operator /(const fraction a) const
    {
        fraction ans;

        ans.num = num * a.den;
        ans.den = den * a.num;

        ans.lowterms();
        return ans;
    }

    bool operator ==(const fraction a) const
    {
        if (num == a.num && den == a.den)
            return true;
        else
            return false;
    }

    bool operator !=(const fraction a) const
    {
        if (num == a.num && den == a.den)
            return false;
        else
            return true;
    }
};

int main()
{
    fraction a, b;
    char op;

    while (1)
    {
        cout << "Enter a fraction:" << endl;
        a.input();
        cout << endl << "Enter another fraction:" << endl;
        b.input();

        if (a == fraction(0, 1) && b == fraction(0, 1))
            break;

        cout << endl << "Enter operand: ";
        cin >> op;

        cout << endl;

        switch (op)
        {
        case '+':
            cout << "Sum = ";
            (a + b).output();
            break;
        case '-':
            cout << "Difference = ";
            (a - b).output();
            break;
        case '*':
            cout << "Product = ";
            (a * b).output();
            break;
        case '/':
            cout << "Difference = ";
            (a / b).output();
            break;
        }

        cout << endl << endl;
    }

    return 0;
}
