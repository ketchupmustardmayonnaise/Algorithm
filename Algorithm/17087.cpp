#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int GCD(int x, int y)
{
	if (x == 0) return y;
	else if (y == 0) return x;
	else return GCD(y, x % y);
}

int main()
{
	vector<int> distance;
	int n, s;
	scanf_s("%d %d", &n, &s);

	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf_s("%d", &temp);
		distance.push_back(abs(temp - s));
	}

	int size = distance.size();

	while (true)
	{
		if (distance.size() <= 1) break;

		int x = distance[size - 1];
		int y = distance[size - 2];

		distance.pop_back();
		distance.pop_back();

		distance.push_back(GCD(x, y));

		size--;
	}

	printf("%d", distance[0]);
}