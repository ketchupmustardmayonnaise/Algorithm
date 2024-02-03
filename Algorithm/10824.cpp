#include <iostream>
#include <string>
using namespace std;

int main()
{
	string numbers[4];

	for (int i = 0; i < 4; i ++)
	{
		string str;
		cin >> str;
		numbers[i] = str;
	}

	string tempNum1 = numbers[0];
	tempNum1.append(numbers[1]);
	long long num1 = stoll(tempNum1);

	string tempNum2 = numbers[2];
	tempNum2.append(numbers[3]);
	long long num2 = stoll(tempNum2);

	cout << num1 + num2 << endl;
}