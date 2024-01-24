#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> stack_of_number;
	int number_of_order;
	cin >> number_of_order;
	if (number_of_order < 1 || number_of_order > 10000) return 0;
	
	for (int i = 0; i < number_of_order; i++)
	{
		string str;
		cin >> str;

		if (str == "push")
		{
			int num;
			cin >> num;
			stack_of_number.push(num);
		}
		else if (str == "top")
		{
			if (stack_of_number.empty()) cout << -1 << '\n';
			else
			{
				cout << stack_of_number.top() << '\n';
			}
		}
		else if (str == "size")
		{
			cout << stack_of_number.size() << "\n";
		}
		else if (str == "empty")
		{
			cout << (stack_of_number.empty() ? 1 : 0) << "\n";
		}
		else if (str == "pop")
		{
			if (stack_of_number.empty()) cout << -1 << '\n';
			else
			{
				cout << stack_of_number.top() << '\n';
				stack_of_number.pop();
			}
		}
	}
}