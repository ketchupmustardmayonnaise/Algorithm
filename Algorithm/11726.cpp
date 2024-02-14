#include <stdio.h>
#define MAX 10001
int num[MAX];

int main()
{
	int n;
	scanf_s("%d", &n);

	num[0] = 0;
	num[1] = 1;
	num[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		num[i] = (num[i - 1] + num[i - 2]) % 10007;
	}

	printf("%d", num[n]);
}