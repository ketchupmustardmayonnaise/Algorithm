#include <iostream>
#include <vector>
using namespace std;

vector<int> sequence;
vector<int> nge;

int main()
{
	int numberOfInput;
	cin >> numberOfInput;

	for (int i = 0; i < numberOfInput; i++)
	{
		int tempNumber;
		cin >> tempNumber;
		sequence.push_back(tempNumber);
	}

	int ngeIndex = 0;
	int ngeNumber = -1;
	for (int i = 0; i < numberOfInput; i++)
	{
		if (i < ngeIndex)
		{
			cout << ngeNumber << ' ';
		}
		else
		{
			ngeNumber = -1;
			if (i < numberOfInput - 1)
			{
				for (int j = i + 1; j < numberOfInput; j++)
				{
					if (sequence[i] < sequence[j])
					{
						ngeIndex = j;
						ngeNumber = sequence[j];
						cout << ngeNumber << ' ';
						break;
					}
				}
			}
			
			if (ngeNumber == -1) cout << "-1" << ' ';
			else if (i == numberOfInput - 1) cout << "-1";
		}
	}
}