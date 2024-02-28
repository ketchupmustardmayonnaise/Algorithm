#include <stdio.h>
using namespace std;

int main()
{
	int dp[10];
	int n;
	scanf_s("%d", &n);

	for (int i = 0; i < 10; i++)
	{
		dp[i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			dp[j] = (dp[j - 1] + dp[j]) % 10007;
		}
	}

	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		count = (count + dp[i]) % 10007;
	}
	printf("%d\n", count);
}