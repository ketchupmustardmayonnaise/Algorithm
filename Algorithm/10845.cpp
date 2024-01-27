#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int number_of_order;
	cin >> number_of_order;

	queue<int> numberQueue;

	for (int i = 0; i < number_of_order; i++)
	{
		string order;
		cin >> order;
		if (order == "push")
		{
			int tempNumber;
			cin >> tempNumber;
			numberQueue.push(tempNumber);
		}
		else if (order == "pop")
		{
			if (!numberQueue.empty())
			{
				cout << numberQueue.front() << '\n';
				numberQueue.pop();
			}
			else cout << "-1" << '\n';
		}
		else if (order == "empty")
		{
			if (numberQueue.empty()) cout << "1" << '\n';
			else cout << "0" << "\n";
		}
		else if (order == "size")
		{
			cout << numberQueue.size() << '\n';
		}
		else if (order == "front")
		{
			if (!numberQueue.empty()) cout << numberQueue.front() << '\n';
			else cout << "-1" << '\n';
		}
		else if (order == "back")
		{
			if (!numberQueue.empty()) cout << numberQueue.back() << '\n';
			else cout << "-1" << '\n';
		}
	}
}