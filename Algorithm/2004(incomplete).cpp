#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	long n, m;
	scanf_s("%d %d", &n, &m);

	if (n - m < m) m = n - m;
	int count2 = 0;
	int count5 = 0;

	for (long i = 1; i <= m; i++)
	{
		long a = n + 1 - i;
		for (long j = a; j % 2 == 0; j /= 2)
		{
			count2++;
		}
		for (long j = a; j % 5 == 0; j /= 5)
		{
			count5++;
		}

		for (long j = i; j % 2 == 0; j /= 2)
		{
			count2--;
		}
		for (long j = i; j % 5 == 0; j /= 5)
		{
			count5--;
		}
	}

	printf("%d\n", min(count2, count5));
}