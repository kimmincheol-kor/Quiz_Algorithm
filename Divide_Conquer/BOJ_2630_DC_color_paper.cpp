#include <iostream>

using namespace std;

int paper[128][128];
int n_color[2] = {0,0};

void check_color(const int len, const int x, const int y)
{
	int standard = paper[x][y];

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if(paper[x + i][y + j] != standard)
			{
				check_color(len / 2, x, y);
				check_color(len / 2, x + len / 2, y);
				check_color(len / 2, x, y + len / 2);
				check_color(len / 2, x + len / 2, y + len / 2);

				return;
			}
		}
	}

	n_color[standard] += 1;
}

/* BOJ 2630 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	
	/* USER INPUT */
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];
	}
	
	/* Processing */
	check_color(N, 0, 0);
	
	/* PRINT RESULT */
	cout << n_color[0] << "\n" << n_color[1];
	
	return 0;
}
