#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int min_number_of_moves;
int board[3][3]; // (y, x)
int current_location[2]; // �� ����(#), (y, x)
priority_queue< pair<int, pair<int, int>>, pair<int, pair<int, int>>, greater<int> > openSet;

int heuristic(int x, int y)
{
	// ��� ����ϴ����� ���� �ٸ��� ������
	// ����... ���� (x,y) ��尡 current_location���� �̵��� ��
	// �� ������ �󸶳� �������� �ϴ����� ����� ��

	int value_of_heuristic = 0;
	int value_of_board = 1;

	board[current_location[0]][current_location[1]] = board[y][x];
	board[y][x] = 0;

	for (int y_ = 0; y_ < 3; y_++)
	{
		for (int x_ = 0; x_ < 3; x_++)
		{
			if (board[y_][x_] != value_of_board)
			{
				value_of_heuristic +=
					(abs(int((board[y_][x_] / 3) - int(value_of_board / 3))) // y�� ����
						+ abs(board[y_][x_] % 3 - value_of_board % 3)); // x�� ����
			}
			value_of_board++;
		}
	}

	// ������ ����
	board[y][x] = board[current_location[0]][current_location[1]];
	board[current_location[0]][current_location[1]] = 0;

	return value_of_heuristic;
}

void GetAroundNode(int x, int y)
{
	for (int y_ = (y > 0 ? y - 1 : 0); y_ < (y > 1 ? 2 : y+1); y_++)
	{
		for (int x_ = (x > 0 ? x - 1 : 0); x_ < (x > 1 ? 2 : x + 1); x++)
		{
			if()
		}
	}
}

int main()
{
	// �Է¹���
	char temporary_char;
	temporary_char = cin.get();
	min_number_of_moves = int(temporary_char);

	temporary_char = cin.get();
	temporary_char = cin.get();

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			temporary_char = cin.get();
			if (temporary_char == '#')
			{
				board[y][x] = 0;
				current_location[0] = y;
				current_location[1] = x;
			}
			else board[y][x] = int(temporary_char) - 48;
		}
		temporary_char = cin.get();
	}
	
	if (min_number_of_moves < 1 || min_number_of_moves > 100) return 0;
	// ����� �̵� Ƚ�� �Է� ��

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			cout << board[y][x] << ' ';
		}
		cout << '\n';
	}

	// ������� A* �˰���
	priority_queue<int, vector<int>, greater<int>> openSet;
	openSet.
}