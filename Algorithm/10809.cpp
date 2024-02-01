#include <iostream>
using namespace std;

int main()
{
	int alphabets[26];
	fill_n(alphabets, 26, -1);

	string str;
	cin >> str;
	
	int index = 0;
	while (index < str.size())
	{
		if (alphabets[str[index] - int('a')] == -1)
		{
			alphabets[str[index] - int('a')] = index;
		}
		index++;
	}

	for (int i = 0; i < size(alphabets) - 1; i++)
	{
		cout << alphabets[i] << ' ';
	}
	cout << alphabets[size(alphabets) - 1];
}