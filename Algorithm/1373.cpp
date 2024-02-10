#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int main()
{
	stack<int> two;
	while (true)
	{
		char temp;
		cin.get(temp);

		if (temp == '\n') break;
		else two.push(int(temp - '0'));
	}

	int power = 0;
	stack<int> eight;
	while (!two.empty())
	{
		if (power == 3) power = 0;
		
		if (power == 0) eight.push(two.top());
		else eight.top() += (two.top() * pow(2, power));
		power++;

		two.pop();
	}

	while (!eight.empty())
	{
		cout << eight.top();
		eight.pop();
	}
}