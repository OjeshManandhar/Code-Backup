#include <iostream>

using namespace std;

struct Distance
{
	int feets;
	float inches;
};

Distance cmpDistance(Distance a, Distance b);

int main()
{
	Distance a, b, ans;

	cout << "Enter feets of the first distance: ";
	cin >> a.feets;
	cout << "Enter inches of the first distance: ";
	cin >> a.inches;
	cout << "Enter feets of the second distance: ";
	cin >> b.feets;
	cout << "Enter inches of the second distance: ";
	cin >> b.inches;

	ans = cmpDistance(a, b);

	cout << endl << "The longer distance is " << ans.feets << "\' - " << ans.inches << "\"." << endl;

	system("pause");
	return 0;
}

Distance cmpDistance(Distance a, Distance b)
{
	float d1, d2;

	d1 = a.feets * 12 + a.inches;
	d2 = b.feets * 12 + b.inches;
	
	if (d1 > d2)
	{
		return a;
	}
	else
	{
		return b;
	}
}
