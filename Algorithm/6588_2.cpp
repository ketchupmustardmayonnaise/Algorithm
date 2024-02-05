#include <stdio.h>
using namespace std;
const int MAX = 1000001;

int prime[MAX];

void Eratos(int num)
{
	for (int index = 2; index * index <= MAX; index++)
	{
		if (prime[index] == index) // 소수라면
		{
			for (int i = index * index; i <= MAX; i += index)
			{
				prime[i] = -1;
			}
		}
	}
}

int main()
{
	for (int i = 0; i < MAX; i++)
	{
		prime[i] = i;
	}
	prime[0] = -1;
	prime[1] = -1;

	Eratos(MAX);

	int n;
	scanf_s("%d", &n);

	while (true)
	{
		if (n == 0) break;

		bool found = false;

		int a;

		for (a = 3; a <= n / 2; a += 2)
		{
			if (prime[a] == a && prime[n - a] == n - a)
			{
				found = true;
				break;
			}
		}

		if (!found) printf("Goldbach's conjecture is wrong.\n");
		else printf("%d = %d + %d\n", n, a, n - a);
		scanf_s("%d", &n);
	}
}