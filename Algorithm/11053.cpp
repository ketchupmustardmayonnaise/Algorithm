#include <stdio.h>
using namespace std;

int main()
{
	int n;
	scanf_s("%d", &n);

	int* numList = new int[n];
	int* dp = new int[n];

	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf_s("%d", &temp);
		numList[i] = temp;

		int maxNum = 0;
		for (int j = 0; j < i; j++)
		{
			if (numList[j] < temp && dp[j] > maxNum) maxNum = dp[j];
		}
		dp[i] = maxNum + 1;
	}

	int maxNum = 0;
	for (int i = 0; i < n; i++)
	{
		if (maxNum < dp[i]) maxNum = dp[i];
		printf("%d\n", dp[i]);
	}
	printf("%d\n", maxNum);

	delete[] dp;
	delete[] numList;
}