#include <stdio.h>
#define MOD 1000000009
#define MAX 1000001 
using namespace std;
int dp[MAX];

int main()
{
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < MAX; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
		dp[i] = (dp[i] + dp[i - 3]) % MOD;
	}

	int t;
	scanf_s("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf_s("%d", &n);
		printf("%d\n", dp[n]);
	}
}