#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, num, den;
    char ch,op;

    do
    {
        cout << "Enter the operation: ";
        cin >> a >> ch >> b >> op >> c >> ch >> d;

        switch (op)
        {
        case '+':
            num = a * d + b * c;
            den = b * d;

            cout << "Answer: " << num << " / " << den << '.' << endl;
            break;

        case '-':
            num = a * d - b * c;
            den = b * d;

            cout << "Answer: " << num << " / " << den << '.' << endl;
            break;

        case '*':
            num = a * c;
            den = b * d;

            cout << "Answer: " << num << " / " << den << '.' << endl;
            break;

        case '/':
            num = a * d;
            den = b * c;

            cout << "Answer: " << num << " / " << den << '.' << endl;
            break;

        default:
            cout << "Wrong Input." << endl;
        }

        cout << endl;
        do
        {
            cout << "Do you want to continue (y/n): ";
            cin >> ch;
        }while (ch != 'y' && ch != 'n');
        cout << endl;
    }while (ch == 'y');

    return 0;
}
