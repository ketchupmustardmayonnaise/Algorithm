#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

int main()
{
	stack<float> postfix_notation;
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
			float a = postfix_notation.top();
			postfix_notation.pop();

			float b = postfix_notation.top();
			postfix_notation.pop();
			postfix_notation.push(float(b * a));
		}
		else if(line[index] == 47)
		{
			float a = postfix_notation.top();
			postfix_notation.pop();

			float b = postfix_notation.top();
			postfix_notation.pop();
			postfix_notation.push(float(b / a));
		}
		else if (line[index] == 43) // +
		{
			postfix_notation.push(103);
		}
		else if (line[index] == 45)
		{
			postfix_notation.push(101);
		}
		else
		{
			postfix_notation.push(char(operand[line[index]]));
		}
		index++;
	}

	stack<float> tempStack;
	while (!(postfix_notation.size() == 1 && tempStack.empty()))
	{
		if (postfix_notation.top() <= 100)
		{
			while (!tempStack.empty())
			{
				postfix_notation.push(tempStack.top());
				tempStack.pop();
			}
		}
		else if (postfix_notation.top() == 103 || postfix_notation.top() == 101)
		{
			int operator_ = int(postfix_notation.top() - 102);
			postfix_notation.pop();
			if (postfix_notation.top() <= 100)
			{
				float a = postfix_notation.top();
				postfix_notation.pop();

				if (postfix_notation.top() <= 100)
				{
					float b = postfix_notation.top();
					postfix_notation.pop();
					postfix_notation.push(float(b + (operator_ * a)));
				}
				else
				{
					if (operator_ == -1) tempStack.push(101);
					else tempStack.push(103);

					tempStack.push(a);
				}
			}
			else
			{
				if (operator_ == -1) tempStack.push(101);
				else tempStack.push(103);
			}
		}
	}

	if (postfix_notation.size() == 1)
	{
		cout << fixed;
		cout.precision(2);
		cout << postfix_notation.top();
	}
}