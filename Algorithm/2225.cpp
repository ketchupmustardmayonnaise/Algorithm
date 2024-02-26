#include <stdio.h>
#define MAX 400
using namespace std;

int main()
{
	int n, k;
	scanf_s("%d %d", &n, &k);

	n = n + k - 1;
	k--;

	if (n - k < k && n - k >= 0) k = n - k;

	int dp[MAX][MAX];
	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= (i < k ? i : k); j++)
		{
			if (j == 0 || j == i) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 1000000000;
		}
	}

	printf("%d\n", dp[n][k]);
}