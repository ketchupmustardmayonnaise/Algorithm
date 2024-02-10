#include <stdio.h>

int Count_Power(long long num, int base)
{
	int count = 0;
	for (int i = base; i <= num; i *= base)
	{
		count += int(num / i);
	}
	return count;
}

int main()
{
	long long n, m;
	scanf_s("%llu %llu", &n, &m);

	if (n - m < m) m = n - m;

	int count5 = Count_Power(n, 5) - Count_Power(n - m, 5) - Count_Power(m, 5);
	int count2 = Count_Power(n, 2) - Count_Power(n - m, 2) - Count_Power(m, 2);

	printf("%d\n", (count2 < count5 ? count2 : count5));
}