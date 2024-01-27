#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

string str;
string print_str;
stack<char> str_stack;

void stack_to_string()
{
	if (!str_stack.empty())
	{
		int stack_size = str_stack.size();
		for (int j = 0; j < stack_size; j++)
		{
			print_str += str_stack.top();
			str_stack.pop();
		}
	}
}

int main()
{
	getline(cin, str);
	bool reverse = true;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '<')
		{
			stack_to_string();
			reverse = false;
			print_str += str[i];
		}
		else if (str[i] == ' ')
		{
			stack_to_string();
			print_str += ' ';
		}
		else if (str[i] == '>')
		{
			reverse = true;
			print_str += str[i];
		}
		else
		{
			if (reverse == false) print_str += str[i];
			else str_stack.push(str[i]);
		}
	}

	stack_to_string();
	cout << print_str << '\n';
}