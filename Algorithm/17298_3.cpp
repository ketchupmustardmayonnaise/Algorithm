#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	vector<int> sequence;
	stack<int> NGE;
	stack<int> NGEindex;

	// ют╥б
	int n;
	cin >> n;

	int maxNum = -1;
	for (int i = 0; i < n; i++)
	{
		int tempNum;
		cin >> tempNum;
		sequence.push_back(tempNum);

		if (i == 0)
		{
			NGE.push(tempNum);
			NGEindex.push(i);
			continue;
		}
		else if (i == n - 1)
		{
			sequence[i] = -1;
		}

		if (tempNum > NGE.top())
		{
			while (tempNum > NGE.top())
			{
				sequence[NGEindex.top()] = tempNum;
				NGE.pop();
				NGEindex.pop();

				if (NGE.empty()) break;
			}
		}
		NGE.push(tempNum);
		NGEindex.push(i);
	}

	while(!NGE.empty())
	{
		sequence[NGEindex.top()] = -1;
		NGE.pop();
		NGEindex.pop();
	}

	for (int i = 0; i < sequence.size()-1; i++)
	{
		cout << sequence[i] << ' ';
	}
	cout << "-1";
}