#include <iostream>
using namespace std;

int GCD(int x, int y)
{
	if (x < y) swap(x, y);

	if (x == 0) return y;
	else if (y == 0) return x;
	else return GCD(y, x%y);
}

int main()
{
	int n;
	cin >> n;

	int index = 0;
	while (index < n)
	{
		int x, y;
		cin >> x >> y;

		cout << x * y / GCD(x, y) << endl;
		index++;
	}
}