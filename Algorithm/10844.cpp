#include <stdio.h>
#define MAX 101

int main()
{
	int** dp = new int* [MAX];
	for (int i = 0; i < MAX; i++)
	{
		dp[i] = new int[10];
	}

	dp[1][0] = 0;
	dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5]
		= dp[1][6] = dp[1][7] = dp[1][8] = dp[1][9] = 1;
	
	for (int i = 2; i < MAX; i++)
	{
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];
		for (int j = 1; j < 9; j++)
		{
			dp[i][j] = (dp[i-1][j - 1] + dp[i-1][j + 1]) % 1000000000;
		}
	}

	int n;
	scanf_s("%d", &n);
	
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		count += dp[n][i];
		count %= 1000000000;
	}
	printf("%d", count);
}