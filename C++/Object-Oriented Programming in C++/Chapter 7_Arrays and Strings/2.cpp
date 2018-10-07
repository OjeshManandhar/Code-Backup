#include <iostream>
#include <string>

using namespace std;

class employee
{
private:
    string name;
    long employee_number;

public:
    employee()
    {}

    void getdata()
    {
        cout << "Enter employee name: ";
        cin >> name;
        cout << "Enter employee number: ";
        cin >> employee_number;
        cout << endl;
    }

    void putdata()
    {
        cout << "Employee name: " << name << endl
             << "Employee number: " << employee_number << endl << endl;
    }
};

int main()
{
    employee data[100];
    int i, j;
    char ch;

    i = -1;
    do
    {
        i++;
        ch = 'N';

        data[i].getdata();

        cout << "Add another [Y/N]: ";
        cin >> ch;
        if (ch == 'y')
            ch = 'Y';

        cout << endl;
    }while (ch == 'Y');

    cout << "Data(s) you've entered:" << endl;
    for (j = 0; j <= i; j++)
        data[j].putdata();

    return 0;
}
