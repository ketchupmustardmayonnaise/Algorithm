#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	string str;
	getline(cin, str);

	int index = 0;
	while (index < str.size())
	{
		if (str[index] >= 'a' && str[index] <= 'z')
		{
			if ('z' - str[index] >= 13) str[index] += 13;
			else
			{
				str[index] += (12 + 'a' - 'z');
			}
		}
		else if (str[index] >= 'A' && str[index] <= 'Z')
		{
			if ('Z' - str[index] >= 13) str[index] += 13;
			else
			{
				str[index] += (12 + 'A' - 'Z');
			}
		}
		index++;
	}

	cout << str << endl;;
}