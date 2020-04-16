#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int N, K;
int coin[100];
int dp[10001];

/* BOJ 2293 */
int main() {

	/* USER INPUT */
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
		scanf("%d", &coin[i]);

	/* Processing */
	dp[0] = 1;

	for (int i = 1; i <= N; i++) // number of coin
		for (int j = coin[i-1]; j <= K; j++)  // target value, coin[i] ~ K
			if (j - coin[i-1] >= 0) // if target value >= coin[i]
				dp[j] += dp[j - coin[i-1]];

	/* PRINT RESULT */
	printf("%d", dp[K]);

	return 0;
}
