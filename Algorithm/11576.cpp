#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
	int beforeNum = 0;
	vector<int> afterNum;

	int a, b, m;
	scanf_s("%d %d\n%d", &a, &b, &m);
	for (int i = 0; i < m; i++)
	{
		int temp;
		scanf_s("%d", &temp);
		beforeNum += temp * pow(a, m - 1 - i);
	}

	int power = 0;
	while (pow(b, power) < beforeNum)
	{
		power++;
	}
	power--;

	int mulNum = pow(b, power);
	while (mulNum > 0)
	{
		int share = beforeNum / mulNum;
		afterNum.push_back(share);
		beforeNum -= share * mulNum;
		mulNum /= b;
	}

	for (int i = 0; i < afterNum.size(); i++)
	{
		printf("%d", afterNum[i]);
		if (i != afterNum.size() - 1) printf(" ");
	}
}