#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;


int main()
{
	stack<char> postfix_notation;
	unordered_map<char, float> operand;

	int n;
	cin >> n;

	string line;
	cin >> line;

	char tempChar = 'A';
	for (int i = 0; i < n; i++)
	{
		int tempNum;
		cin >> tempNum;
		operand[tempChar] = float(tempNum);
		tempChar++;
	}

	int index = 0;
 	while (index < line.size())
	{
		if (line[index] == 42) // °öÇÏ±â
		{
			int a = operand[postfix_notation.top()];
			operand.erase(postfix_notation.top());
			postfix_notation.pop();

			int b = operand[postfix_notation.top()];
			operand[postfix_notation.top()] = float(b * a);
		}
		else if(line[index] == 47)
		{
			float a = operand[postfix_notation.top()];
			operand.erase(postfix_notation.top());
			postfix_notation.pop();

			float b = operand[postfix_notation.top()];
			operand[postfix_notation.top()] = float(b / a);
		}
		else
		{
			postfix_notation.push(char(line[index]));
		}
		index++;
	}

	stack<char> tempStack;
	while (postfix_notation.size() != 1)
	{
		if (postfix_notation.top() > 64)
		{
			while (!tempStack.empty())
			{
				postfix_notation.push(tempStack.top());
				tempStack.pop();
			}
		}
		else if (postfix_notation.top() == '+' || postfix_notation.top() == '-')
		{
			int operator_ = int(postfix_notation.top() - 44) * -1;
			postfix_notation.pop();
			if (postfix_notation.top() > 64)
			{
				char a = postfix_notation.top();
				postfix_notation.pop();

				if (postfix_notation.top() > 64)
				{
					float b = operand[postfix_notation.top()];
					operand.erase(a);
					operand[postfix_notation.top()] = float(b + (operator_ * operand[a]));
				}
				else
				{
					if (operator_ == -1) tempStack.push('-');
					else tempStack.push('+');

					tempStack.push(a);
				}
			}
			else
			{
				if (operator_ == -1) tempStack.push('-');
				else tempStack.push('+');
			}
		}
	}

	if (postfix_notation.size() == 1)
	{
		cout << operand[postfix_notation.top()];
	}
}