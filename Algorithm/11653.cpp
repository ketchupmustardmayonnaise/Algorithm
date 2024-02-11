#include <stdio.h>
#define MAX 10000001
int num[MAX];

void Goldbach()
{
	for (int i = 2; i*i <= MAX; i++)
	{
		if (num[i] == i)
		{
			for (int j = i * i; j <= MAX; j+=i)
			{
				num[j] = -1;
			}
		}
	}
}

int main()
{
	num[0] = -1;
	num[1] = -1;
	for (int i = 2; i < MAX; i++)
	{
		num[i] = i;
	}
	Goldbach();

	int n;
	scanf_s("%d", &n);

	int index = 2;
	while (n != 1)
	{
		if (num[index] == index && n % index == 0)
		{
			printf("%d\n", index);
			n /= index;
		}
		else
		{
			index++;
		}
	}
}