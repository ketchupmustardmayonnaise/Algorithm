#include <stdio.h>

int gcd(int x, int y)
{
	if (x == 0) return y;
	else if (y == 0) return x;
	else return gcd(y, x % y);
}

int main()
{
	int t, n;
	scanf_s("%d", &t);

	for (int i = 0; i < t; i++)
	{
		scanf_s("%d", &n);
		int* list = new int[n];

		long long count = 0;
		for (int j = 0; j < n; j++)
		{
			int temp;
			scanf_s("%d", &temp);
			list[j] = temp;

			for (int k = j-1; k >= 0; k--)
			{
				if (list[k] > temp) count+=gcd(list[k], temp);
				else count += gcd(temp, list[k]);
			}
		}
		printf("%llu\n", count);
		delete[] list;

	}
}