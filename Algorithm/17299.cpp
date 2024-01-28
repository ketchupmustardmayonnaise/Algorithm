#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	int n;
	cin >> n;

	unordered_map<int, int> m;
	vector<int> sequence;
	for (int i = 0; i < n; i++)
	{
		int tempNumber;
		cin >> tempNumber;

		if (m.count(tempNumber) == 0) m[tempNumber] = 1;
		else m[tempNumber]++;

		sequence.push_back(tempNumber);
	}

	stack<int> NGF;
	stack<int> NGFindex;
	NGF.push(m[sequence[0]]);
	NGFindex.push(0);

	for (int i = 1; i < n; i++)
	{
		while (m[sequence[i]] > NGF.top())
		{
			NGF.pop();
			sequence[NGFindex.top()] = sequence[i];
			NGFindex.pop();

			if (NGF.empty()) break;
		}

		NGF.push(m[sequence[i]]);
		NGFindex.push(i);
	}
	while (!NGF.empty())
	{
		sequence[NGFindex.top()] = -1;
		NGF.pop();
		NGFindex.pop();
	}
	sequence[n - 1] = -1;

	for (int i = 0; i < n-1; i++) cout << sequence[i] << ' ';
	cout << sequence[n - 1];
}