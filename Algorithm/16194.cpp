#include <stdio.h>
#define MAX 100001
using namespace std;

int main()
{
	int** dp = new int* [MAX];
	for (int i = 0; i < MAX; i++)
	{
		dp[i] = new int[3];
	}

	dp[0][0] = dp[0][1] = dp[0][2] = dp[1][1] = dp[1][2] = dp[2][0] = dp[2][2] = 0;
	dp[1][0] = dp[2][1] = dp[3][0] = dp[3][1] = dp[3][2] = 1;

	for (int i = 4; i < MAX; i++)
	{
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % 1000000009;
		dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % 1000000009;
		dp[i][2] = (dp[i - 3][0] + dp[i - 3][1]) % 1000000009;
	}

	int t;
	scanf_s("%d", &t);
	for (int t_case = 0; t_case < t; t_case++)
	{
		int n;
		scanf_s("%d", &n);

		printf("%d\n", ((dp[n][0] + dp[n][1]) % 1000000009 + dp[n][2]) % 1000000009);
	}
}