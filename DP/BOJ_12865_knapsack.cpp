#include <iostream>
#include <stdlib.h>

#define MAX(a,b) a > b ? a : b

using namespace std;

int N;
int W[101];
int V[101];

int K;

int board[101][100001];

void DP_knapsack(int n)
{
	// n번째 물건을 챙길때, 안챙길때(이전 값) 값의 MAX

	int remain;

	int include;
	int exclude;

	if (n > N)
		return;
	else
	{
		for (int bag = 1; bag <= K; bag++)
		{
			if (W[n] <= bag) // 챙길 수 있다.
			{
				// 챙긴다.
				remain = bag - W[n];
				include = V[n] + board[n-1][remain];

				// 안챙긴다.
				exclude = board[n - 1][bag];

				// 비교. -> 입력. -> 종료.
				board[n][bag] = MAX(include, exclude);
			}
			else // 챙길 수 없다.
			{
				board[n][bag] = board[n - 1][bag];
			}
		}

		DP_knapsack(n+1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	memset(board, 0, sizeof(board));

	for (int i = 1; i <= N; i++)
		cin >> W[i] >> V[i];

	DP_knapsack(1);

	cout << board[N][K] << "\n";
	
	return 0;
}
