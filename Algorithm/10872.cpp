#include <stdio.h>
using namespace std;

int main()
{
	int n;
	scanf_s("%d", &n);

	int count = 1;
	for (int i = 1; i <= n; i++)
	{
		count *= i;
	}

	printf("%d\n", count);
}