#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int min_number_of_moves;
int board[3][3]; // (y, x)
int current_location[2]; // 빈 공간(#), (y, x)
priority_queue< pair<int, pair<int, int>>, pair<int, pair<int, int>>, greater<int> > openSet;

int heuristic(int x, int y)
{
	// 어떻게 계산하는지에 따라 다르긴 하지만
	// 나는... 현재 (x,y) 노드가 current_location으로 이동한 후
	// 각 노드들이 얼마나 움직여야 하는지를 계산할 것

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
					(abs(int((board[y_][x_] / 3) - int(value_of_board / 3))) // y값 차이
						+ abs(board[y_][x_] % 3 - value_of_board % 3)); // x값 차이
			}
			value_of_board++;
		}
	}

	// 원상태 복구
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
	// 입력받음
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
	// 보드와 이동 횟수 입력 끝

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			cout << board[y][x] << ' ';
		}
		cout << '\n';
	}

	// 여기부터 A* 알고리즘
	priority_queue<int, vector<int>, greater<int>> openSet;
	openSet.
}