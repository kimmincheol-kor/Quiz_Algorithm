#include <cstdio>

using namespace std;

int board[64][64];

void QT(const int& n, const int& x, const int& y)
{
	int standard = board[y][x];
	bool flag = false;

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
		printf("%d", standard);
	}
	else
	{
		printf("\(");

		QT(n / 2, x, y);
		QT(n / 2, x + n / 2, y);
		QT(n / 2, x, y + n / 2);
		QT(n / 2, x + n / 2, y + n / 2);

		printf("\)");
	}

	return;
}

/* BOJ 1992 */
int main() {
	int N;

	/* USER INPUT */
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf_s("%1d", &board[i][j]);
		}
	}

	/* Processing */
	QT(N, 0, 0);

	/* PRINT RESULT */


	return 0;
}

/*
when using ios::sync_with_stdio(false),
can't use both 'scanf' and 'cin'

and 'cout', 'cin' is slower than 'printf', 'scanf'
*/
