#include <stdio.h>
#define MAX 1000
using namespace std;

int main()
{
	int dp[MAX][3];

	int n;
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int r, g, b;
		scanf_s("%d %d %d", &r, &g, &b);

		if (i == 0)
		{
			dp[i][0] = r;
			dp[i][1] = g;
			dp[i][2] = b;
			continue;
		}

		dp[i][0] = (dp[i - 1][1] < dp[i - 1][2] ? dp[i - 1][1] : dp[i - 1][2]) + r;
		dp[i][1] = (dp[i - 1][0] < dp[i - 1][2] ? dp[i - 1][0] : dp[i - 1][2]) + g;
		dp[i][2] = (dp[i - 1][0] < dp[i - 1][1] ? dp[i - 1][0] : dp[i - 1][1]) + b;
	}

	int min = (dp[n - 1][0] < dp[n - 1][1] ? dp[n - 1][0] : dp[n - 1][1]);
	min = (min < dp[n - 1][2] ? min : dp[n - 1][2]);
	printf("%d\n", min);
}