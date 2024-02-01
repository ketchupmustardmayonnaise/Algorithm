#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

int main()
{
	vector<char> printSentence;
	stack<char> operators;

	unordered_map<char, int> priority;
	priority['*'] = 2;
	priority['/'] = 2;
	priority['+'] = 1;
	priority['-'] = 1;

	string line;
	cin >> line;

	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] > 64) printSentence.push_back(line[i]);
		else
		{
			if (line[i] == '(')
			{
				operators.push('.');
			}
			else if (line[i] == ')')
			{
				while (true)
				{
					if (operators.top() == '.')
					{
						operators.pop();
						break;
					}
					printSentence.push_back(operators.top());
					operators.pop();
				}
			}
			else if (!operators.empty() && priority[line[i]] > priority[operators.top()])
			{
				operators.push(line[i]);
			}
			else
			{
				while (!operators.empty())
				{
					if (priority[operators.top()] < priority[line[i]]) break;
					if (operators.top() == '.') break;
					printSentence.push_back(operators.top());
					operators.pop();
				}
				operators.push(line[i]);
			}
		}
	}

	while (!operators.empty())
	{
		if(operators.top() != '.') printSentence.push_back(operators.top());
		operators.pop();
	}

	for (int i = 0; i < printSentence.size(); i++)
	{
		cout << printSentence[i];
	}
}