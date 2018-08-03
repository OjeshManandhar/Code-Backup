#include <iostream>

using namespace std;

int main()
{
	struct point
	{
		int cord_x;
		int cord_y;
	}p1, p2, sum;

	cout << "Enter co-ordinates for p1: ";
	cin >> p1.cord_x >> p1.cord_y;
	cout << "Enter co-ordinates for p1: ";
	cin >> p2.cord_x >> p2.cord_y;

	sum.cord_x = p1.cord_x + p2.cord_x;
	sum.cord_y = p1.cord_y + p2.cord_y;

	cout << endl << "Co-ordinates of p1+p2 are: " << sum.cord_x << ", " << sum.cord_y << endl;

	system("pause");
	return 0;
}