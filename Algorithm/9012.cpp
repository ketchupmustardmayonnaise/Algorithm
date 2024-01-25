#include <iostream>
#include <sstream>
using namespace std;

int vpsCount;

bool VPS(int x)
{
	if (x == -1)
	{
		vpsCount--;
		if (vpsCount < 0) return false;
	}
	else if (x == 1)
	{
		vpsCount++;
	}
	return true;
}

int main()
{
	int number_of_test_case;
	cin >> number_of_test_case;
	cin.ignore();

	for (int i = 0; i < number_of_test_case; i++)
	{
		vpsCount = 0;
		string str;
		getline(cin, str);
		str.resize(50);

		int strIndex = 0;
		bool vpsBool = true;
		while (strIndex < str.size() && vpsBool)
		{
			if (str[strIndex] == '(') vpsBool = VPS(1);
			else if (str[strIndex] == ')') vpsBool = VPS(-1);
			strIndex++;
		}

		if (vpsCount != 0) vpsBool = false;

		if (vpsBool) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}