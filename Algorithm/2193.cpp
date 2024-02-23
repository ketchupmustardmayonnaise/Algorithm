#include <stdio.h>
#define MAX 91

int main()
{
	long long** dp = new long long* [MAX];
	for (int i = 0; i < MAX; i++)
	{
		dp[i] = new long long[2];
	}

	dp[0][0] = dp[0][1] = dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 2; i < MAX; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	int n;
	scanf_s("%d", &n);
	printf("%llu\n", dp[n][0] + dp[n][1]);
}