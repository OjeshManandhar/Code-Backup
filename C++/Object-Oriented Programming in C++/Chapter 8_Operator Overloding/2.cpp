#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class String
{
private:
    enum {SIZE = 100};
    char str[SIZE];

public:
    String()
    {
        strcpy(str, "");
    }

    String(char *data)
    {
        strcpy(str, data);
    }

    void display() const
    {
        cout << str;
    }

    void getstring()
    {
        cout << "Enter a string: ";
        cin >> str;
    }

    String operator +=(const String s)
    {
        if ((strlen(str) + strlen(s.str)) >= SIZE)
        {
            cout << "Overload" << endl;
            return String();
        }
        else
        {
            strcat(str, s.str);
            return String(str);
        }
    }
};

int main()
{
    String a, b, c;

    cout << "Enter for a" << endl;
    a.getstring();
    cout << endl << "Enter for b" << endl;
    b.getstring();

    cout << endl;
    b.display();
    cout << " is concatenated to ";
    a.display();
    cout << endl;

    c = a += b;

    cout << endl << "New string a: ";
    a.display();
    cout << endl << endl << "New string b: ";
    b.display();
    cout << endl << endl << "New string c: ";
    c.display();
    cout << endl;

    return 0;
}
