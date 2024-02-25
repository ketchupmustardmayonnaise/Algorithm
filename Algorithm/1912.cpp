#include <stdio.h>
#include <algorithm>
#define MAX 100001
using namespace std;

int main()
{
	int a[MAX];
	int dp[MAX];
	int n;

	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf_s("%d", &temp);
		a[i] = temp;
		
		if (i > 0)
		{
			dp[i] = (dp[i - 1] + temp > temp ? dp[i - 1] + temp : temp);
		}
		else dp[i] = temp;
	}

	int max = *max_element(dp, dp + n);
	printf("%d\n", max);
}