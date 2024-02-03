#include <iostream>
using namespace std;

int GCD(int x, int y)
{
	if (x == 0) return y;
	else if (y == 0) return x;
	else return GCD(y, x % y);
}

int main()
{
	int x, y;
	cin >> x >> y;
	cout << GCD(x, y) << endl;
	cout << x * y / GCD(x, y) << endl;
}