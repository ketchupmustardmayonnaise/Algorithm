#include <stdio.h>
#define MAX 1000001
int prime[MAX];

void Goldbach()
{
	for (int i = 2; i*i <= MAX; i++)
	{
		if (prime[i] == i) // �Ҽ����
		{
			for (int j = i * i; j <= MAX; j += i)
			{
				prime[j] = -1;
			}
		}
	}
}

int main()
{
	// �ʱ�ȭ
	prime[0] = -1;
	prime[1] = -1;
	for (int i = 2; i < MAX; i++)
	{
		prime[i] = i;
	}
	Goldbach();

	int t, n;
	scanf_s("%d", &t);
	
	for (int i = 0; i < t; i++)
	{
		scanf_s("%d", &n);
		int count = 0;
		for (int j = 2; j <= n / 2; j++)
		{
			if (prime[j] == j && prime[n - j] == n - j) count++;
		}
		printf("%d\n", count);
	}
}