#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int num)
{
	int index = 2;
	while (index <= sqrt(num))
	{
		if (num % index == 0) return false;
		index++;
	}
	return true;
}

int main()
{ 
	int n;
	cin >> n;

	while(n != 0)
	{

		int a, b;
		a = 3;
		b = n - a;

		bool isThisConjTrue = false;
		while (a <= n / 2)
		{
			if (isPrime(a) && isPrime(b))
			{
				isThisConjTrue = true;
				break;
			}
			else
			{
				a += 2;
				b -= 2;
			}
		}

		if (isThisConjTrue) cout << n << " = " << a << " + " << b << '\n';
		else cout << "Goldbach's conjecture is wrong.\n";

		cin >> n;
	}
}