#include <iostream>

using namespace std;

class counter
{
private:
    static unsigned int c;
public:
    counter()
    {
        c++;
    }
    void show()
    {
        cout << c << ' ';
    }
    ~counter()
    {
        c--;
    }
};

unsigned int counter::c = 0;

int main()
{
    counter a, b, *obj = NULL;

    cout << "Created two objects 'a' abd 'b'." << endl;
    cout << "Value of count in a, b: ";
    a.show();
    b.show();

    cout << endl << endl << "Creating 2 dynamic objects in 'obj'." << endl;
    obj = new counter[2];
    cout << "Value of count in a, b: ";
    a.show();
    b.show();
    cout << "Value of count in obj[0], obj[1]: ";
    obj[0].show();
    obj[1].show();

    cout << endl << endl << "Deleting the dynamic objects." << endl;
    delete[] obj;
    cout << "Value of count in a, b: ";
    a.show();
    b.show();

    return 0;
}
/*
Output:
Created two objects 'a' abd 'b'.
Value of count in a, b: 2, 2

Creating 2 dynamic objects in 'obj'.
Value of count in a: 4, 4
Value of count in obj[0], obj[1]: 4, 4

Deleting the dynamic objects.
Value of count in a, b: 2,2
*/
