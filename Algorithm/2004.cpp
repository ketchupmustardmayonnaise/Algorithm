#include <stdio.h>
using namespace std;

int Count_fac(long long num, int div_num)
{
	int count = 0; // 5의 총 개수
	int factor = 0; // 현재 지수가 몇인지를 구함
	long long x = div_num;
	while (x <= num)
	{
		// 가장 큰 x와 그에 상응하는 지수를 구함
		factor++;
		if (x * div_num > num) break;
		else x *= div_num;
	}

	int previous_count = 0;
	for (x; x >= div_num; x /= div_num)
	{
		long long a = int(num / x);
		count += factor * (a - previous_count);
		previous_count += (a - previous_count);
		factor--;
	}

	return count;
}

int main()
{
	long long n, m;
	scanf_s("%llu %llu", &n, &m);

	if (n - m < m) m = n - m;

	int count5 = Count_fac(n, 5) - Count_fac(n - m, 5) - Count_fac(m, 5);
	int count2 = Count_fac(n, 2) - Count_fac(n - m, 2) - Count_fac(m, 2);

	printf("%d\n", (count2 < count5 ? count2 : count5));
}