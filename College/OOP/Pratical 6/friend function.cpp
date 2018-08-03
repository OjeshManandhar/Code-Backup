#include <iostream>

using namespace std;

class one;
class two;

class one
{
private:
    int n;
public:
    friend void swap_data(one &, two &);
    void getdata()
    {
        cout << "Enter data for n in one: ";
        cin >> n;
    }
    void showdata() const
    {
        cout << "Value of n in one: " << n << endl;
    }
};

class two
{
private:
    int n;
public:
    friend void swap_data(one &, two &);
    void getdata()
    {
        cout << "Enter data for n in two: ";
        cin >> n;
    }
    void showdata() const
    {
        cout << "Value of n in two: " << n << endl;
    }
};

void swap_data(one &a, two &b)
{
    int temp = a.n;
    a.n = b.n;
    b.n = temp;
}

int main()
{
    one x;
    two y;

    x.getdata();
    y.getdata();

    cout << endl << "Before swapping:" << endl;
    x.showdata();
    y.showdata();

    cout << endl << "After swapping:" << endl;
    swap_data(x, y);
    x.showdata();
    y.showdata();

    return 0;
}
/*
Output:
Enter data for n in one: 4
Enter data for n in two: 5

Before swapping:
Value of n in one: 4
Value of n in two: 5

After swapping:
Value of n in one: 5
Value of n in two: 4
*/
