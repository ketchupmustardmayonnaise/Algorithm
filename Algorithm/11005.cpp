#include <stdio.h>
#include <string>
#include <stack>
using namespace std;

char num[36]= { '0', '1', '2', '3', '4',
				'5', '6', '7', '8', '9',
				'A', 'B', 'C', 'D', 'E',
				'F', 'G', 'H', 'I', 'J',
				'K', 'L', 'M', 'N', 'O',
				'P', 'Q', 'R', 'S', 'T',
				'U', 'V', 'W', 'X', 'Y', 'Z' };

int main()
{
	int n, b;
	scanf_s("%d %d", &n, &b);

	stack<int> convertNum;

	int share = n;
	while (true)
	{
		int tempShare = share / b;
		int remain = share % b;
		convertNum.push(remain);
		share = tempShare;

		if (tempShare * b + remain < b) break;
	}

	string printStr = "";
	while (!convertNum.empty())
	{
		printStr += num[convertNum.top()];
		convertNum.pop();
	}
	
	while (printStr.size() != 1 && printStr[0] == '0')
	{
		printStr.substr(1, printStr.size() - 1);
	}

	printf("%s", printStr.c_str());
}