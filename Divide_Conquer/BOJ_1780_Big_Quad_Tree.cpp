#include <iostream>
#include <cstdio>

using namespace std;

int ** board;
int cnt[3] = { 0, 0, 0 };

void QT(const int& n, const int& x, const int& y)
{
	int standard = board[y][x];
	bool flag = false;

	if (n == 1)
	{
		cnt[standard + 1]++;
		return;
	}

	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
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
		cnt[standard + 1]++;
	}
	else
	{
		int div = n / 3;

		QT(div, x, y);
		QT(div, x + div, y);
		QT(div, x + div + div, y);

		QT(div, x, y + div);
		QT(div, x + div, y + div);
		QT(div, x + div + div, y + div);

		QT(div, x, y + div + div);
		QT(div, x + div, y + div + div);
		QT(div, x + div + div, y + div + div);
	}

	return;
}

/* BOJ 1780 */
int main() {
	int N;

	/* USER INPUT */
	scanf("%d", &N);

	board = new int* [N];
	for (int i = 0; i < N; i++)
		board[i] = new int[N];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}

	/* Processing */
	QT(N, 0, 0);

	/* PRINT RESULT */
	for (int i = 0; i < 3; i++)
		printf("%d\n", cnt[i]);

	return 0;
}
