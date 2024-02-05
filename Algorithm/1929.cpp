#include <iostream>
using namespace std;

const int MAX = 1000000 + 1;
int num[MAX];

int main()
{
	int minNum, maxNum;
	cin >> minNum >> maxNum;

	// �ʱ�ȭ
	num[0] = -1;
	num[1] = -1;
	for (int i = 2; i <= maxNum; i++)
	{
		num[i] = i;
	}
	
	for (int index = 2; index * index <= maxNum; index++)
	{
		if (num[index] == index) // �Ҽ���� �ɷ���
		{
			for (int i = index * index; i <= maxNum; i += index)
			{
				num[i] = -1;
			}
		}
	}
	
	for (int i = minNum; i <= maxNum; i++)
	{
		if (num[i] == i) cout << i << '\n';
	}
}