#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	vector<int> sequence;
	stack<int> NGEsequence;

	// 입력
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
				if (sequence[i] < NGEsequence.top()) // NGE값을 찾은 경우
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
				else // NGE에서 tempStack으로 옮겨 가며 계속 search
				{
					tempStack.push(NGEsequence.top());
					NGEsequence.pop();
				}
			}

			// 다시 원상복구해 줌
			while (!tempStack.empty())
			{
				NGEsequence.push(tempStack.top());
				tempStack.pop();
			}

			// NGE 못 찾은 경우 -1
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