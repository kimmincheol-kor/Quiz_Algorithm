#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int board[9][9];

bool check_col[9][9];
bool check_row[9][9];
bool check_box[9][9];

void Finish_sdoku()
{
	// Print
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			cout << board[y][x];
			if (x != 8)
				cout << " ";
		}
		cout << "\n";
	}
	exit(0);
}

void DFS_sdoku(int num_block)
{
	if (num_block > 80)
		Finish_sdoku();
	else
	{
		int num_box;
		int value_block;

		int new_value;

		int x = num_block % 9;
		int y = num_block / 9;

		// DFS method
		num_box = (x / 3) * 3 + y / 3;
		value_block = board[y][x];

		if (value_block == 0) // need service.
		{
			for (int i = 0; i < 9; i++) // 0~8 test
			{
				if (check_row[y][i] == false && check_col[x][i] == false && check_box[num_box][i] == false)
				{
					// input new number
					check_row[y][i] = true;
					check_col[x][i] = true;
					check_box[num_box][i] = true;
					board[y][x] = i + 1;

					DFS_sdoku(num_block + 1); // Do the next block

					// if reach here => Fail to Finish.
					check_row[y][i] = false;
					check_col[x][i] = false;
					check_box[num_box][i] = false;
					board[y][x] = 0;
				}
			}
		}
		else
			DFS_sdoku(num_block + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input;

	// Input Board
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			cin >> input;

			board[y][x] = input;

			if (input != 0)
			{
				check_row[y][input-1] = true;
				check_col[x][input-1] = true;
				check_box[(x / 3) * 3 + y / 3][input-1] = true;
			}
		}
	}

	DFS_sdoku(0);

	return 0;
}