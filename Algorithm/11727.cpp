#include <stdio.h>
#define MAX 1001

int main()
{
	int n;
	scanf_s("%d", &n);

	int dp1[MAX];
	int dp2[MAX];

	dp1[0] = 0;
	dp2[0] = 0;
	dp1[1] = 1;
	dp2[1] = 2;

	for (int i = 2; i < MAX; i++)
	{
		dp2[i] = (2 * dp2[i - 2] + dp2[i - 1]) % 10007;
		dp1[i] = (dp2[i-1] + dp1[i - 1]) % 10007;
	}

	printf("%d", dp1[n]);
}