#include <iostream>

using namespace std;

int main()
{
    float a,b;
    char op,choice;

    do
    {
        cout << "Enter first number, operator, second number: ";
        cin >> a >> op >> b;

        switch (op)
        {
        case '+':
            cout << "Answer: " << a+b << endl;
            break;
        case '-':
            cout << "Answer: " << a-b << endl;
            break;
        case '*':
            cout << "Answer: " << a*b << endl;
            break;
        case '/':
            cout << "Answer: " << a/b << endl;
            break;
        default:
            cout << "Wrong Input." << endl;
        }

        cout << endl << "Do another (y/n): ";
        cin >> choice;
        cout << endl;
    }while (choice == 'y');

    return 0;
}
