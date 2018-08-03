#include <iostream>

using namespace std;

int main()
{
    int n=10;

    cout << n << endl;
    cout << (n+=10) << endl;        //OR cout << (n*=2) << endl;
    cout << --n << endl;
    return 0;
}
