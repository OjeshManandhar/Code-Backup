#include <iostream>

using namespace std;

class complex_no
{
    float real, img;
public:
    complex_no(float r = 0, float i = 0)
    {
        real = r;
        img = i;
    }
    void getdata()
    {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> img;
    }
    void showdata() const
    {
        if (img >= 0)
            cout << '(' << real << '+' << img << 'i' << ')' << endl;
        else
            cout << '(' << real << img << 'i' << ')' << endl;
    }
    friend complex_no operator --(complex_no &, int);
    friend complex_no operator *(complex_no, complex_no);
    complex_no operator ++()
    {
        return complex_no(++real, ++img);
    }
    complex_no operator +(complex_no c) const
    {
        return complex_no(real + c.real, img + c.img);
    }
    complex_no operator -(complex_no c) const
    {
        return complex_no(real - c.real, img - c.img);
    }
};

complex_no operator --(complex_no &c, int)
{
    return complex_no(c.real--, c.img--);
}

complex_no operator *(complex_no a, complex_no b)
{
    complex_no temp;
    temp.real = a.real*b.real - a.img*b.img;
    temp.img = a.real*b.img + a.img*b.real;
    return temp;
}

int main()
{
    complex_no a, b, c;

    cout << "Enter a complex number in a." << endl;
    a.getdata();
    cout << endl << "Enter another complex number in b." << endl;
    b.getdata();

    cout << endl << "++a = ";
    ++a;
    a.showdata();

    cout << "b-- = ";
    b--;
    b.showdata();

    cout << "a + b = ";
    c = a + b;
    c.showdata();

    cout << "b - a = ";
    c = b - a;
    c.showdata();

    cout << "2 * b = ";
    c = 2*b;
    c.showdata();

    return 0;
}
/*
Output:
Enter a complex number in a.
Enter real part: 4.9
Enter imaginary part: -5.7


Enter another complex number in b.
Enter real part: 2.6
Enter imaginary part: 5.21

++a = (5.9-4.7i)
b-- = (1.6+4.21i)
a + b = (7.5-0.49i)
b - a = (-4.3+8.91i)
2 * b = (3.2+8.42i)
*/
