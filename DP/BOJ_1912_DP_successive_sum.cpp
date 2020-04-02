#include <iostream>

using namespace std;

int N;

int max_of_3(int a, int b, int c)
{
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

/* BOJ 1912 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* USER INPUT */
	cin >> N;
	
	int** dp = new int*[N];
	for (int i = 0; i < N; i++)
		dp[i] = new int[3];

	for (int i = 0; i < N; i++)
		cin >> dp[i][0];

	/* Processing */
	dp[0][1] = dp[0][0];
	dp[0][2] = -1001;

	for (int i = 1; i < N; i++)
	{
		dp[i][1] = max_of_3(dp[i][0], dp[i-1][0]+dp[i][0], dp[i-1][1]+dp[i][0]);
		
		dp[i][2] = max_of_3(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);

		if (dp[i][2] < dp[i][1])
			dp[i][2] = -1001;
	}

	/* PRINT RESULT */
	cout << max_of_3(dp[N-1][0], dp[N - 1][1], dp[N - 1][2]);

	return 0;
}
