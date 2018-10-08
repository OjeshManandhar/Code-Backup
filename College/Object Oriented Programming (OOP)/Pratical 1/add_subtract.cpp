#include <iostream>

using namespace std;

float add(float a, float b)
{
    return (a + b);
}

float subtract(float a, float b)
{
    return (a - b);
}

int main()
{
    float a, b;

    cout << "Enter two numbers [SEPARATED BY A SPACE]: ";
    cin >> a >> b;

    cout << endl << a << " + " << b << " = " << add(a, b) << endl;
    cout << a << " - " << b << " = " << subtract(a, b) << endl;

    return 0;
}
