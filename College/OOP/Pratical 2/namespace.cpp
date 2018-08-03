#include <iostream>

using namespace std;

namespace first
{
    int x = 5, y = 2;
}

namespace second
{
    float x = 10.2, y = 5.9;
}

int main()
{
    {
        using namespace first;
        cout << "x = " << x << endl << "y = " << y << endl;
    }

    cout << endl << "x = " << second::x << endl << "y = " << second::y << endl;

    return 0;
}
