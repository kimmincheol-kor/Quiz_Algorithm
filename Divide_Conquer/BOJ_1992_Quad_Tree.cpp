#include <iostream>

using namespace std;

int** board;

void QT(const int &n, const int &x, const int &y)
{
	int standard = board[y][x];
	bool flag = false;

	if (n == 1)
	{
		cout << standard;
		return;
	}

	for (int i = y; i < y+n; i++)
	{
		for (int j = x; j < x+n; j++)
		{
			if (board[i][j] != standard)
			{
				flag = true;
				break;
			}
		}

		if (flag == true)
			break;
	}

	if (flag == false)
	{
		cout << standard;
	}
	else
	{
		cout << "(";

		QT(n / 2, x, y);
		QT(n / 2, x + n / 2, y);
		QT(n / 2, x, y + n / 2);
		QT(n / 2, x + n / 2, y + n / 2);

		cout << ")";
	}

	return;
}

/* BOJ 1992 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	/* USER INPUT */
	cin >> N;

	board = new int* [N];
	for (int i = 0; i < N; i++)
		board[i] = new int[N];

	for (int i = 0; i < N; i++)
	{
		int line;
		cin >> line;

		for (int j = 0; j < N; j++)
		{
			board[i][N - 1 - j] = line % 10;
			line /= 10;
		}
	}

	/* Processing */
	QT(N,0,0);

	/* PRINT RESULT */


	return 0;
}
