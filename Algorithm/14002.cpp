#include <stdio.h>
#include <stack>
#define MAX 1001
using namespace std;

int main()
{
	int n;
	scanf_s("%d", &n);

	int numList[MAX];
	int dp[MAX];
	int index[MAX];
	stack<int> sequence;

	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf_s("%d", &temp);
		numList[i] = temp;

		int maxNum = 0;
		int tempIndex = -1;
		for (int j = 0; j < i; j++)
		{
			if (numList[j] < temp && dp[j] > maxNum)
			{
				maxNum = dp[j];
				tempIndex = j;
			}
		}
		dp[i] = maxNum + 1;
		index[i] = tempIndex;
	}

	int maxNum = 0;
	int tempIndex = 0;
	for (int i = 0; i < n; i++)
	{
		if (maxNum < dp[i])
		{
			maxNum = dp[i];
			tempIndex = i;
		}
	}
	printf("%d\n", maxNum);

	while (true)
	{
		if (tempIndex == -1) break;
		else
		{
			sequence.push(numList[tempIndex]);
			tempIndex = index[tempIndex];
		}
	}

	while (!sequence.empty())
	{
		printf("%d", sequence.top());
		sequence.pop();
		if (!sequence.empty()) printf(" ");
	}
	printf("\n");
}