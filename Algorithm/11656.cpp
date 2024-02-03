#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> suffix;
	string str;
	cin >> str;
	
	int index = 0;
	while (index < str.size())
	{
		suffix.push_back(str.substr(index, str.size()));
		index++;
	}
	sort(suffix.begin(), suffix.end());

	index = 0;
	while (index < suffix.size())
	{
		cout << suffix[index] << endl;
		index++;
	}
}