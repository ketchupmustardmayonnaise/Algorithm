#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> stack_sequence;
int max_stack_number;
int currentPushIndex;

vector<char> printCharacters;

bool Sequence_of_stack(int number)
{
	while (true)
	{
		if (currentPushIndex < number)
		{
			currentPushIndex++;
			stack_sequence.push(currentPushIndex);

			printCharacters.push_back('+');
			printCharacters.push_back('\n');
		}
		else if (currentPushIndex == number)
		{
			stack_sequence.pop();
			printCharacters.push_back('-');
			printCharacters.push_back('\n');
			return true;
		}
		else
		{
			if (stack_sequence.top() == number)
			{
				stack_sequence.pop();
				printCharacters.push_back('-');
				printCharacters.push_back('\n');
				return true;
			}
			else return false;
		}
	}
	return false;
}

int main()
{
	int max_stack_number;
	cin >> max_stack_number;

	currentPushIndex = 0;

	int tempNumber;
	bool canMakeSequence = true;
	for (int i = 0; i < max_stack_number; i++)
	{
		cin >> tempNumber;
		if(canMakeSequence) canMakeSequence = Sequence_of_stack(tempNumber);
	}

	if (canMakeSequence == false) cout << "NO";
	else
	{
		for (int i = 0; i < printCharacters.size(); i++)
		{
			cout << printCharacters[i];
		}
	}
}