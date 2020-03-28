#include <iostream>

using namespace std;

int N;

int* rgb[3];
int* dp[3];

int min(int x, int y)
{
	return x < y ? x : y;
}

/* BOJ 1149 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < 3; i++)
	{
		rgb[i] = new int[N];
		dp[i] = new int[N];
	}
	
	/* USER INPUT */
	for (int i = 0; i < N; i++) 
	{
		cin >> rgb[0][i] >> rgb[1][i] >> rgb[2][i];

		dp[0][i] = rgb[0][i];
		dp[1][i] = rgb[1][i];
		dp[2][i] = rgb[2][i];

		/* Processing */
		if (i > 0)
		{
			dp[0][i] += min(dp[1][i - 1], dp[2][i - 1]);
			dp[1][i] += min(dp[0][i - 1], dp[2][i - 1]);
			dp[2][i] += min(dp[0][i - 1], dp[1][i - 1]);
		}
	}

	cout << min(min(dp[0][N - 1], dp[1][N - 1]), dp[2][N-1]) << "\n";

	return 0;
}
