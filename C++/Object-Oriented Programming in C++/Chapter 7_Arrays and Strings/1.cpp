#include <iostream>
#include <cstring>

using namespace std;

void reversit(char *data)
{
    char temp;
    int i, j;

    for (i = 0, j = strlen(data) - 1; i < j; i++, j--)
    {
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}

int main()
{
    char data[101];

    cout << "Enter a string: ";
    cin.get(data, 100, '\n');

    reversit(data);

    cout << endl << "Reversed string: " << data << endl;

    return 0;
}
