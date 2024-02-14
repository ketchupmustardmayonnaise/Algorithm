#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> dp;
	dp.push_back(0);

	scanf_s("%d\n", &n);

	for (int i = 1; i <= n; i++)
	{
		int temp;
		scanf_s("%d", &temp);
		
		dp.push_back(temp);

		for (int j = 1; j <= i / 2; j++)
		{
			if (dp[j] + dp[i - j] > dp[i])
				dp[i] = dp[j] + dp[i - j];
		}
	}

	printf("%d", dp[n]);
}