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
    }
    void output() const
    {
        cout << num << '/' << den << endl;
    }
    fraction fadd(const fraction a)
    {
        fraction ans;

        ans.num = num * a.den + den * a.num;
        ans.den = den * a.den;

        ans.lowterms();
        return ans;
    }
    fraction fsub(const fraction a)
    {
        fraction ans;

        ans.num = num * a.den - den * a.num;
        ans.den = den * a.den;

        ans.lowterms();
        return ans;
    }
    fraction fmul(const fraction a)
    {
        fraction ans;

        ans.num = num * a.num;
        ans.den = den * a.den;

        ans.lowterms();
        return ans;
    }
    fraction fdiv(const fraction a)
    {
        fraction ans;

        ans.num = num * a.den;
        ans.den = den * a.num;

        ans.lowterms();
        return ans;
    }
};

int main()
{
    short int flag = 0;
    fraction a, b, ans;
    char op;

    a.input();
    cout << endl << "Enter operator: ";
    cin >> op;
    cout << endl;
    b.input();

    switch (op)
    {
    case '+':
        ans = a.fadd(b);
        break;
    case '-':
        ans = a.fsub(b);
        break;
    case '*':
        ans = a.fmul(b);
        break;
    case '/':
        ans = a.fdiv(b);
        break;
    default:
        flag = 1;
        cout << endl << "Wrong input." << endl;
    }
    if (flag != 1)
    {
        cout << endl << "Answer = ";
        ans.output();
    }

    system("pause");
    return 0;
}
