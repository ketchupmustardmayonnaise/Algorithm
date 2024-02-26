#include <stdio.h>
#include <math.h>
#include <vector>
#define MAX 100001
using namespace std;

int main()
{
	int dp[MAX];
	int n;
	scanf_s("%d", &n);

	dp[0] = 0;
	dp[1] = 1;
	vector<int> sqrtNum;

	for (int i = 2; i <= n; i++)
	{
		if (int(sqrt(i)) * int(sqrt(i)) == i)
		{
			dp[i] = 1;
			sqrtNum.push_back(i);
		}
		else
		{
			dp[i] = dp[i - 1];
			for (int j = 2; j * j < i; j++)
			{
				dp[i] = (dp[i] < dp[i - j * j] ? dp[i] : dp[i - j * j]);
			}
			dp[i]++;
		}
	}

	printf("%d\n", dp[n]);
}