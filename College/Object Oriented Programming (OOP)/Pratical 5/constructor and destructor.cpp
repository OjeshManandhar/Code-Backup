#include <iostream>

using namespace std;

class counter
{
public:
    counter()
    {
        cout << "Constructor called." << endl;
    }
    ~counter()
    {
        cout << "Destructor called." << endl;
    }
};

int main()
{
    counter a, *obj = NULL;

    cout << "Created a static object." << endl;

    cout << endl << "Creating a dynamic object." << endl;
    obj = new counter;

    cout << endl << "Deleting the dynamic object." << endl;
    delete obj;

    cout << endl << "Closing the program, deleting the static object." << endl;

    return 0;
}
/*
Output:
Constructor called.
Created a static objects.

Creating a dynamic object.
Constructor called.

Deleting the dynamic object.
Destructor called.

Closing the program, deleting the static object.
Destructor called.
*/
