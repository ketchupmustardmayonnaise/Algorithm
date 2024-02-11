#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	stack<int> eight;
	while (true)
	{
		char temp;
		cin.get(temp);

		if (temp == '\n') break;
		else eight.push(int(temp - '0'));
	}

	stack<int> two;
	while (!eight.empty())
	{
		stack<int> tempStack;
		for (int power = 4; power >= 1; power /= 2)
		{
			if (eight.top() >= power)
			{
				tempStack.push(int(eight.top() / power));
				eight.top() -= power;
			}
			else tempStack.push(0);
		}
		eight.pop();
		while (!tempStack.empty())
		{
			two.push(tempStack.top());
			tempStack.pop();
		}
	}

	string str;
	while (!two.empty())
	{
		str.push_back(char(two.top() + '0'));
		two.pop();
	}
	
	while (str[0] == '0' && str.size() != 1)
	{
		str = str.substr(1, str.size() - 1);
	}
	cout << str;
}