#include <iostream>
#include <deque>
using namespace std;

int main()
{
	int number_of_order;
	cin >> number_of_order;

	deque<int> integerDeque;

	for (int i = 0; i < number_of_order; i++)
	{
		string order;
		cin >> order;

		if (order == "push_back")
		{
			int tempNumber;
			cin >> tempNumber;
			integerDeque.push_back(tempNumber);
		}
		else if (order == "push_front")
		{
			int tempNumber;
			cin >> tempNumber;
			integerDeque.push_front(tempNumber);
		}
		else if (order == "front")
		{
			if (integerDeque.empty()) cout << "-1\n";
			else cout << integerDeque.front() << '\n';
		}
		else if (order == "back")
		{
			if (integerDeque.empty()) cout << "-1\n";
			else cout << integerDeque.back() << '\n';
		}
		else if (order == "empty")
		{
			if (integerDeque.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (order == "size")
		{
			cout << integerDeque.size() << '\n';
		}
		else if (order == "pop_front")
		{
			if (integerDeque.empty()) cout << "-1\n";
			else
			{
				cout << integerDeque.front() << '\n';
				integerDeque.pop_front();
			}
		}
		else if (order == "pop_back")
		{
			if (integerDeque.empty()) cout << "-1\n";
			else
			{
				cout << integerDeque.back() << '\n';
				integerDeque.pop_back();
			}
		}
	}
}