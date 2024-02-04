#include <iostream>
using namespace std;

bool prime_number(int n)
{
	if (n == 1) return false;
	else if (n == 2) return true;
	else if (n % 2 == 0) return false;
	else
	{
		int k = 3;
		while (k <= n / 2)
		{
			if (n % k == 0) return false;
			k++;
		}
		return true;
	}
}

int main()
{
	int n;
	cin >> n;

	int prime = 0;

	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		if (prime_number(number)) prime++;
	}

	cout << prime << endl;
}