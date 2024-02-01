#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	while (true)
	{
		cin.clear();

		int lower = 0;
		int upper = 0;
		int num = 0;
		int gap = 0;

		string str;
		getline(cin, str);

		int index = 0;
		while (index < str.size())
		{
			if (str[index] >= 'a' && str[index] <= 'z') lower++;
			else if (str[index] >= 'A' && str[index] <= 'Z') upper++;
			else if (str[index] >= '0' && str[index] <= '9') num++;
			else if (str[index] == ' ') gap++;
			index++;
		}

		if (lower == 0 && upper == 0 && num == 0 && gap == 0) break;

		cout << lower << ' ' << upper << ' ' << num << ' ' << gap << endl;
	}
}