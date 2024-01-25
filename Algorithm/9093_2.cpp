#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int number_of_test_case;
	cin >> number_of_test_case;
	cin.ignore();

	for (int i = 0; i < number_of_test_case; i++)
	{
		string str;
		getline(cin, str);
		str.resize(10000);
		
		int start = 0;
		int end = 1;
		vector<stack<char>> sentence;
		while (end != -1)
		{
			end = str.find(' ', start);

			stack<char> word;
			int index = start;
			while (true)
			{
				if (str[index] == '\0' || str[index] == ' ') break;
				word.push(str[index]);
				index++;
			}
			sentence.push_back(word);
			start = end + 1;
		}

		for (int j = 0; j < sentence.size(); j++)
		{
			int size = sentence[j].size();
			for (int k = 0; k < size; k++)
			{
				cout << sentence[j].top();
				sentence[j].pop();
			}
			cout << ' ';
		}
		cout << '\n';
	}
}