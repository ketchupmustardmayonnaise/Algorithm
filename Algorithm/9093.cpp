#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	char str[20];
	
	int test_case;
	cin >> test_case;
	
	for (int i = 0; i < test_case; i++)
	{
		vector<string> words;
		while (true)
		{
			cin >> str;
			words.push_back(str);
			if (cin.get() == '\n') break;
		}

		for (int i = 0; i < words.size(); i++)
		{
			for (int j = 0; j < words[i].size() / 2; j++)
			{
				char temp = words[i][j];
				words[i][j] = words[i][words[i].size() - 1 - j];
				words[i][words[i].size() - 1 - j] = temp;
			}

			cout << words[i];
			if (i != words.size() - 1) cout << ' ';
		}
		cout << '\n';
	}
}