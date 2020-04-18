#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int N, K;
int W[100];
int V[100];

int dp[2][100001];

/* BOJ 12865 */
int main() {

	/* USER INPUT */
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
		scanf("%d %d", &W[i], &V[i]);

	/* Processing */
	dp[0][0] = 0;
	dp[1][0] = 0;

	int slide = 1;

	for (int num = 0; num < N; num++) // number of using product
	{
		// 0 ~ W[num]-1 : Copy
		for(int a = 0; a<W[num]; a++)
			dp[slide % 2][a] = dp[(slide - 1) % 2][a];

		// W[num] ~ K : Check Max
		for (int a = W[num]; a <= K; a++)
		{
			if (dp[(slide - 1) % 2][a - W[num]] + V[num] > dp[(slide - 1) % 2][a])
				dp[slide % 2][a] = dp[(slide - 1) % 2][a - W[num]] + V[num];
			else
				dp[slide % 2][a] = dp[(slide - 1) % 2][a];
		}

		slide++;
	}

	/* PRINT RESULT */
	if(dp[slide % 2][K] > dp[(slide-1) % 2][K])
		printf("%d", dp[slide % 2][K]);
	else
		printf("%d", dp[(slide - 1) % 2][K]);

	return 0;
}
