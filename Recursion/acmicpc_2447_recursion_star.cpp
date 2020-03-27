#include <iostream>

using namespace std;

int N;

char board[3000][3000];

// Run
void run(int n, int x, int y)
{
	if (n == 3)
	{
		board[y][x] = '*';
		board[y][x + 1] = '*';
		board[y][x + 2] = '*';

		board[y + 1][x] = '*';
		//board[y + 1][x + 1] = ' ';
		board[y + 1][x + 2] = '*';

		board[y + 2][x] = '*';
		board[y + 2][x + 1] = '*';
		board[y + 2][x + 2] = '*';
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == 1 && j == 1)
					continue;
				else
					run(n / 3, x + n / 3 * j, y + n / 3 * i);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = ' ';
		}
	}

	run(N, 0, 0);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << board[i][j];
		}
		if (i != N - 1)
			cout << "\n";
	}

	return 0;
}