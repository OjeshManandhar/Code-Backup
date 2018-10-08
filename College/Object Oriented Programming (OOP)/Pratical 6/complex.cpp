#include <iostream>

using namespace std;

class complex_no
{
private:
    int real, img;
public:
    friend complex_no mul_no(complex_no, complex_no);
    complex_no()
    {
        real = img = 0;
    }
    complex_no(int a)
    {
        real = a;
        img = 0;
    }
    complex_no(int a, int b)
    {
        real = a;
        img = b;
    }
    void show_no()
    {
        if (img >= 0)
            cout << '(' << real << '+' << img << 'i' << ')';
        else
            cout << '(' << real << img << 'i' << ')';
    }
};

complex_no mul_no(complex_no a, complex_no b)
{
    complex_no temp;
    temp.real = a.real*b.real - a.img*b.img;
    temp.img = a.real*b.img + a.img*b.real;
    return temp;
}

int main()
{
    complex_no a(2), b(5, 6), c(3, -5), d;

    d = mul_no(a, b);
    a.show_no();
    cout << " * ";
    b.show_no();
    cout << " = ";
    d.show_no();

    cout << endl;
    d = mul_no(2, c);
    cout << "2 * ";
    c.show_no();
    cout << " = ";
    d.show_no();

    return 0;
}
/*
Output:
(2+0i) * (5+6i) = (10+12i)
2 * (3-5i) = (6-10i)
*/
