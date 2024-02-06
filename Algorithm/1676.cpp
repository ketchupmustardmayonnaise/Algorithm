#include <stdio.h>
using namespace std;

int main()
{
	int n;
	scanf_s("%d", &n);

	int count2 = 0;
	int count5 = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j % 2 == 0; j /= 2)
		{
			count2++;
		}
		for (int j = i; j % 5 == 0; j /= 5)
		{
			count5++;
		}
	}

	printf("%d\n", (count2 < count5 ? count2 : count5));
}