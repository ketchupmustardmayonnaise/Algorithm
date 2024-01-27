#include <iostream>
#include <list>
using namespace std;

list<int> sequence;
list<int> print_sequence;

void NextIter(list<int>::iterator& it)
{
	if (it == sequence.end()) it = sequence.begin();
	else it++;
}

int main()
{
	// n, k 입력받음
	int n, k;
	cin >> n >> k;
	if (n < 1 || n > 5000) return 0;
	else if (k < 1 || k > 5000) return 0;

	// sequence 리스트 초기화
	for (int i = 0; i < n; i++)
	{
		sequence.push_back(i+1);
	}

	list<int>::iterator iter; iter = sequence.end();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k-1; j++)
		{
			NextIter(iter);
		}
		print_sequence.push_back(*iter);
		iter = sequence.erase(iter); // 여기서 한 번 이동이 됨
	}

	for (int i = 0; i < n; i++)
	{
		cout << print_sequence.front() << ' ';
		print_sequence.pop_front();
	}
}