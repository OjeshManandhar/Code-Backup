#include <iostream>

using namespace std;

class complex_no
{
private:
    int real, img;
public:
    complex_no()
    {
        real = img = 0;
    }
    void getdata()
    {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> img;
    }
    void showdata()
    {
        if (img >= 0)
            cout << real << " +" << img << 'i' << endl;
        else
            cout << real << ' ' << img << 'i' << endl;
    }
    complex_no add_no(complex_no a)
    {
        complex_no temp;

        temp.real = real + a.real;
        temp.img = img + a.img;

        return temp;
    }
    complex_no sub_no(complex_no a)
    {
        complex_no temp;

        temp.real = real - a.real;
        temp.img = img - a.img;

        return temp;
    }
};

int main()
{
    complex_no a, b, c;

    cout << "Enter a complex number:" << endl;
    a.getdata();

    cout << endl << "Enter another complex number: " << endl;
    b.getdata();

    cout << endl <<"Sum = ";
    c = a.add_no(b);
    c.showdata();

    cout << "Difference = ";
    c = a.sub_no(b);
    c.showdata();

    return 0;
}
/*
Output:
Enter a complex number:
Enter real part: 2
Enter imaginary part: 3

Enter another complex number:
Enter real part: 6
Enter imaginary part: 8

Sum = 8 +11i
Difference = -4 -5i
*/
