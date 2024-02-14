#include <stdio.h>
#define MAX 1000001

int num[MAX];

int main()
{
	int n;
	scanf_s("%d", &n);

	num[0] = -1;
	num[1] = 0;
	num[2] = 1;
	num[3] = 1;

	int index = 2;
	for (int index = 4; index <= n; index++)
	{
		if (index % 3 == 0 && num[index / 3] < num[index - 1]
			&& !(index % 2 == 0 && num[index / 3] > num[index / 2]))
			num[index] = num[index / 3] + 1;
		else if (index % 2 == 0 && num[index / 2] < num[index - 1])
			num[index] = num[index / 2] + 1;
		else num[index] = num[index - 1] + 1;
	}

	printf("%d", num[n]);
}