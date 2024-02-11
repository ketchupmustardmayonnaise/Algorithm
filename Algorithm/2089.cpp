#include <stdio.h>
#include <stack>
#include <math.h>
using namespace std;

int main()
{
	int n;
	scanf_s("%d", &n);

	stack<int> minus_two;
	int share = n;
	while (true)
	{
		int temp = share / (- 2); // ¸ò
		if (share < 0 && share % 2 != 0) temp++;

		int remain = share - (temp * (-2)); // ³ª¸ÓÁö
		minus_two.push(share - (temp * (-2)));
		share = temp;

		if (share == 0) break;
	}

	while (!minus_two.empty())
	{
		printf("%d", minus_two.top());
		minus_two.pop();
	}
}