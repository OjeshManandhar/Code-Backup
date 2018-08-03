#include <iostream>

#include <string.h>
#include <cstdlib>

using namespace std;

char *to_string(const int);
char *to_string(const float, const short int = 4);

int main()
{
	int i = 101;
	float f = 12509.99f;
	char *ch;

	ch = to_string(i);
	cout << ch << endl;
	ch = to_string(f, 0);
	cout << ch << endl;

	system("pause");
	return 0;
}

char *to_string(const int n)
{
	int rem, temp, length = 0, i;
	char *ans = NULL;

	temp = n;
	while (temp != 0)
	{
		i = ++length - 1;
		rem = temp % 10;
		ans = (char *)realloc(ans, length * sizeof(char));
		ans[i] = rem + 48;
		temp /= 10;
	}
	ans[length] = 0;

	return _strrev(ans);
}

char *to_string(const float f, const short int dec_count)
{
	int i, length, rem, count;
	float dec;
	char *ans = NULL;

	i = static_cast<int>(f);
	ans = to_string(i);
	length = strlen(ans);

	dec = f - i;
	if (dec == 0 || dec_count == 0)
	{
		return ans;
	}

	ans[length] = '.';
	length++;
	ans[length] = 0;

	for (count = 1; count <= dec_count + 1; count++)
	{
		dec *= 10;
		rem = static_cast<int>(dec) % 10;
		i = ++length - 1;
		ans[i] = rem + 48;
	}
	ans[length] = 0;
	do
	{
		count = length - 1;
		if (ans[count] > '5' && ans[count - 1] != 9)
		{
			ans[count - 1]++;
			ans[count] = 0;
			length--;
		}
		else
		{
			return ans;
		}

		if (ans[count] == '9' && ans[count - 1] == '.')
		{
			return to_string(static_cast<int>(f) + 1);
		}
	} while (ans[count - 1] != '9' || ans[count] != '.');

	return NULL;
}
