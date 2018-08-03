#include <iostream>

#include <cstring>

using namespace std;

int to_numberi(const char *);
float to_numberf(const char *, const short int = 4);

int main()
{
	int i;
	float f;
	char chi[] = "12350", chf[] = "253.89";

	i = to_numberi(chi);
	f = to_numberf(chf, 2);

	cout << "i = " << i << endl;
	cout << "f = " << f << endl;

	system("pause");
	return 0;
}

int to_numberi(const char *ch)
{
	int i, ans = 0, length;

	length = strlen(ch);
	for (i = 0; i < length; i++)
	{
		ans = ans * 10 + ch[i] - 48;
	}

	return ans;
}

float to_numberf(const char *ch, const short int dec_count)
{
	int  flag = 0, i, length;
	float divider = 10, ans = 0, temp;

	length = strlen(ch);
	for (i = 0; i < length; i++)
	{
		if (ch[i] == '.')
		{
			i++;
			flag = 1;
		}
		if (flag == 0)
		{
			ans = ans * 10 + ch[i] - 48;
		}
		else if (flag == 1)
		{
			temp = ch[i] - 48;
			temp /= divider;
			ans += temp;
			divider *= 10;
		}
	}

	return ans;
}