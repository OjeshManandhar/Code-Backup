#include <iostream>

using namespace std;

class alpha
{
private:
    int data;
public:
    alpha(): data(99)
    {}
    friend class beta;
};

class beta
{
public:
    void showdata(alpha a)
    {
        cout << "Value of data in class alpha [displaying from beta]: " << a.data << endl;
    }
};

int main()
{
    alpha a;
    beta b;

    b.showdata(a);

    return 0;
}
/*
Output:
Value of data in class alpha [displaying from beta]: 99
*/
