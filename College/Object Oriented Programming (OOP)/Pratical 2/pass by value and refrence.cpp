#include <iostream>

using namespace std;

void swap_value(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap_refrence(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x, y;

    cout << "Enter value for x: ";
    cin >> x;
    cout << "Enter value for y: ";
    cin >> y;

    cout << endl << "Swapping by pass by value:" << endl;
    swap_value(x, y);
    cout << "x = " << x << '\t' << "y : " << y << endl;

    cout << endl << "Swapping by pass by refrence:" << endl;
    swap_refrence(x, y);
    cout << "x = " << x << '\t' << "y : " << y << endl;

    return 0;
}
