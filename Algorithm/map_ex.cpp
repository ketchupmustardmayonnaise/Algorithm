#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

void TempFunction(std::pair<string, int> pair)
{
	cout << pair.first << ' ' << pair.second << '\n';
}

int main()
{
	unordered_map<string, int> m;

	// insert 
	m["a"] = 1;
	m["temp"] = 9;
	m["a"] = 7;

	// 반복 호출
	cout << "\n### 1\n";
	for (auto& kv : m)
	{
		cout << kv.first << ' ' << kv.second << '\n';
	}

	cout << "\n### 2\n";
	for_each(m.begin(), m.end(), TempFunction);

	cout << "\n### 3\n";
	unordered_map<string, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << ' ' << it->second << '\n';
	}

	cout << "\n### 4\n";
	for(pair<string, int> atom : m)
	{
		cout << atom.first << ' ' << atom.second << '\n';
	}

	// find
	cout << "\n### find 1\n";
	cout << m.find("a")->first << ' ' << m.find("a")->second << '\n';
	// m.find의 결과는 iterator다. 따라서 화살표 연산이 필요!

	cout << "\n### find 2\n";
	cout << "temp" << ' ' << m["temp"] << '\n';

	// erase
	m.erase("a");
	m.erase(m.find("temp"));
}