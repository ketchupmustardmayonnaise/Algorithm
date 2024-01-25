#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

// editor1는 제대로 되어 있지만
// editor2는 거꾸로 되어 있음.
stack<char> editor1;
stack<char> editor2;

int cursor;

void cursorMoveLeft()
{
	if (!editor1.empty())
	{
		editor2.push(editor1.top());
		editor1.pop();
	}
}

void cursorMoveRight()
{
	if (!editor2.empty())
	{
		editor1.push(editor2.top());
		editor2.pop();
	}
}

void insertCharacterCursorLeft(char ch)
{
	editor1.push(ch);
}

void deleteCharacterCursorLeft()
{
	if(!editor1.empty()) editor1.pop();
}

int main()
{
	char ch;
	while (true)
	{
		ch = cin.get();
		if (ch == '\n') break;
		if (islower(ch)) editor1.push(ch);
	}
	
	int number_of_order;
	cin >> number_of_order;

	for (int i = 0; i < number_of_order; i++)
	{
		cin.ignore();
		char order = cin.get();
		switch (order)
		{
		case 'P':
			cin.ignore();
			ch = cin.get();
			insertCharacterCursorLeft(ch);
			break;
		case 'L':
			cursorMoveLeft();
			break;
		case 'D':
			cursorMoveRight();
			break;
		case 'B':
			deleteCharacterCursorLeft();
			break;
		}
	}

	int tempSize = editor1.size();
	for (int i = 0; i < tempSize; i++)
	{
		editor2.push(editor1.top());
		editor1.pop();
	}
	tempSize = editor2.size();
	for (int i = 0; i < tempSize; i++)
	{
		cout << editor2.top();
		editor2.pop();
	}
}