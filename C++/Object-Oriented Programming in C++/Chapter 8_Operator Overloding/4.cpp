#include <iostream>
#include <stdint.h>

using namespace std;

class Int
{
private:
    int n;

public:
    Int(): n(0)
    {}

    Int(int i): n(i)
    {}

    void getdata()
    {
        cin >> n;
    }

    void showdata()
    {
        cout << n;
    }

    Int operator +(const Int i) const
    {
        int64_t temp;

        temp = n + i.n;

        if (temp < -2147483647 || temp > 2147483648)
        {
            cout << "Overload" << endl;
            return 0;
        }
        else
            return Int(static_cast<int>(temp));
    }

    Int operator -(const Int i) const
    {
        int64_t temp;

        temp = n - i.n;

        if (temp < -2147483647 || temp > 2147483648)
        {
            cout << "Overload" << endl;
            return 0;
        }
        else
            return Int(static_cast<int>(temp));
    }

    Int operator *(const Int i) const
    {
        long double temp;
        long double tempa = n;
        long double tempb = i.n;

        temp = tempa*tempb;

        if (temp < -2147483647 || temp > 2147483648)
        {
            cout << "Overload" << endl;
            return 0;
        }
        else
            return Int(static_cast<int>(temp));
    }

    Int operator /(const Int i) const
    {
        int64_t temp;

        temp = n / i.n;

        if (temp < -2147483647 || temp > 2147483648)
        {
            cout << "Overload" << endl;
            return 0;
        }
        else
            return Int(static_cast<int>(temp));
    }
};

int main()
{
    Int a, b;

    cout << "Enter value for a: ";
    a.getdata();
    cout << "Enter value for b: ";
    b.getdata();

    cout << endl << "a + b = ";
    (a + b).showdata();
    cout << endl << "a - b = ";
    (a - b).showdata();
    cout << endl << "a * b = ";
    (a * b).showdata();
    cout << endl << "a / b = ";
    (a / b).showdata();
    cout << endl << endl;

    return 0;
}
