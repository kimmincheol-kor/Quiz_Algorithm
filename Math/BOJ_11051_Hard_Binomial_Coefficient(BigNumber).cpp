#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

using namespace std;

int dp[1001][1001];

int Paskal(int n, int k)
{
	if (n == 1 || k == 0 || n == k)
		return 1;
	else if (dp[n][k] != -1)
		return dp[n][k];
	else
		dp[n][k] = (Paskal(n - 1, k - 1) + Paskal(n - 1, k)) % 10007;

	return dp[n][k];
}

/* BOJ 11051 */
int main() {
	int N, K;

	/* USER INPUT */
	scanf("%d %d", &N, &K);

	/* Processing */
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= K; j++)
			dp[i][j] = -1;

	/* PRINT RESULT */
	printf("%d", Paskal(N, K));

	return 0;
}
