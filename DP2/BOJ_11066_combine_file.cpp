#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int T, K;
int size[500];
int sum[500];

int min_val(int a, int b)
{
	return a < b ? a : b;
}

/* BOJ 11066 */
int main() {

	/* USER INPUT */
	scanf("%d", &T);

	for (int q = 0; q < T; q++)
	{
		scanf("%d", &K);

		scanf("%d", &size[0]);
		sum[0] = size[0];

		for (int a = 1; a < K; a++)
		{
			scanf("%d", &size[a]);
			sum[a] = sum[a - 1] + size[a];
		}

		/* Processing */
		int dp[500][500];

		dp[K - 1][K - 1] = 0; // K~K = 0

		for (int a = K-2; a >= 0; a--) // line.
		{
			// fixed value.
			dp[a][a] = 0;
			dp[a][a + 1] = size[a] + size[a + 1];
			
			// need check.
			for (int b = a+2; b < K; b++)
			{
				dp[a][b] = 100000000;

				for (int c = 0; c < b-a; c++)
				{
					dp[a][b] = min_val(dp[a][b], dp[a][a + c] + dp[a + c + 1][b]);
				}

				if (a > 0)
					dp[a][b] += sum[b] - sum[a-1];
				else
					dp[a][b] += sum[b];
			}
		}

		/* PRINT RESULT */
		printf("%d\n", dp[0][K-1]);
	}

	/* Processing */
	/* PRINT RESULT */

	return 0;
}
