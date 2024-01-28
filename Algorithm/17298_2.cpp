#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	vector<int> sequence;
	stack<int> NGEsequence;

	// �Է�
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int tempNum;
		cin >> tempNum;
		sequence.push_back(tempNum);
	}

	NGEsequence.push(-1);
	for (int i = n-2; i >= 0; i--)
	{
		if (sequence[i] < sequence[i + 1]) NGEsequence.push(sequence[i + 1]);
		else if (sequence[i] < NGEsequence.top()) NGEsequence.push(NGEsequence.top());
		else if (!NGEsequence.empty())
		{
			stack<int> tempStack;
			bool needToNGEfound = true;
			while (!NGEsequence.empty() && needToNGEfound)
			{
				if (sequence[i] < NGEsequence.top()) // NGE���� ã�� ���
				{
					int NGENum = NGEsequence.top();
					while (!tempStack.empty())
					{
						NGEsequence.push(tempStack.top());
						tempStack.pop();
					}
					NGEsequence.push(NGENum);
					needToNGEfound = false;
				}
				else // NGE���� tempStack���� �Ű� ���� ��� search
				{
					tempStack.push(NGEsequence.top());
					NGEsequence.pop();
				}
			}

			// �ٽ� ���󺹱��� ��
			while (!tempStack.empty())
			{
				NGEsequence.push(tempStack.top());
				tempStack.pop();
			}

			// NGE �� ã�� ��� -1
			if (needToNGEfound) NGEsequence.push(-1);
		}
		else NGEsequence.push(-1);
	}

	while (!NGEsequence.empty())
	{
		cout << NGEsequence.top();
		NGEsequence.pop();
		if (!NGEsequence.empty()) cout << ' ';
	}
}