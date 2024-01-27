#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

int main()
{
	stack<int> stack_of_bar;

	string str;
	getline(cin, str);

	int index = 0;
	while (index < str.size())
	{
		if (str[index] == '(')
		{
			if (str[index + 1] == ')')
			{
				stack_of_bar.push(0);
				index+=2;
			}
			else
			{
				stack_of_bar.push(-1);
				index++;
			}
		}
		else if (str[index] == ')')
		{
			stack_of_bar.push(1);
			index++;
		}
	}

	int time_of_slice = 0;
	stack<int> slice;

	while (!stack_of_bar.empty())
	{
		if (stack_of_bar.top() == 0)
		{
			if (!slice.empty())
			{
				int temp = slice.top() + 1;
				slice.pop();
				slice.push(temp);
			}
		}
		else
		{
			if (stack_of_bar.top() == 1)
			{
				slice.push(0);
			}
			else if (stack_of_bar.top() == -1)
			{
				int tempNumber = 0;
				if (!slice.empty())
				{
					tempNumber = slice.top();
					time_of_slice += (slice.top() + 1);
					slice.pop();
				}
				if (!slice.empty()) slice.top() += tempNumber;
			}
		}

		if(!stack_of_bar.empty()) stack_of_bar.pop();
	}
	std::cout << time_of_slice << '\n';
}