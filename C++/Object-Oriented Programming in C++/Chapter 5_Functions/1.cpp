#include <iostream>

using namespace std;

float circarea(const float rad);

int main()
{
	//float circarea(const float rad);

	float rad;

	cout << "Enter the radius of the circle: ";
	cin >> rad;

	cout << endl << "The area of the circle is: " << circarea(rad) << '.' << endl;

	system("pause");
	return 0;
}

float circarea(const float rad)
{
	return (3.151592653589793*rad*rad);
}