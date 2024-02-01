#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

int main()
{
	stack<float> operand;
	unordered_map<char, int> matching_float;

	int n;
	cin >> n;

	string line;
	cin >> line;

	char indexChar = 'A';
	for (int i = 0; i < n; i++)
	{
		int tempNum;
		cin >> tempNum;
		matching_float[indexChar] = tempNum;
		indexChar++;
	}

	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] >= 'A' && line[i] <= 'Z')
		{
			operand.push(matching_float[line[i]]);
		}
		else
		{
			float b = operand.top();
			operand.pop();
			float a = operand.top();
			operand.pop();

			float newFloat;
			switch (line[i])
			{
			case '+':
				newFloat = float(a + b);
				break;
			case '-':
				newFloat = float(a - b);
				break;
			case '*':
				newFloat = float(a * b);
				break;
			case '/':
				newFloat = float(a / b);
				break;
			}
			operand.push(newFloat);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << operand.top();
}