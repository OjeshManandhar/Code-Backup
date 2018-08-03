#include <iostream>

using namespace std;

int main()
{
    int choice;
    float cel,far;

    cout << "Type 1 to convert Fahrenheit to Celsius," << endl
         << "     2 to convert Celsius to Fahrenheit: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << endl << "Enter temperature in Fahrenheit: ";
        cin >> far;

        cel = (far - 32) * 5 / 9;

        cout << endl << "In Celsius that's " << cel << endl;
        break;
    case 2:
        cout << endl << "Enter temperature in Celsius: ";
        cin >> cel;

        far = (cel * 9 / 5) + 32;

        cout << endl << "In Fahrenheit that's " << far << endl;
        break;
    default:
        cout << endl << "Wrong Input." << endl;
    }

    return 0;
}
