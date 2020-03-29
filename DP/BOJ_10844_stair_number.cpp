#include <iostream>
#define DIV 1000000000

using namespace std;

int N;

/* BOJ 10844 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* USER INPUT */
	cin >> N;

	/* Processing */
	int dp_result[2][10];

	dp_result[1][0] = 0;
	for (int i = 1; i <= 9; i++)
		dp_result[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
				dp_result[i % 2][j] = dp_result[(i - 1) % 2][j + 1] % DIV;
			else if (j == 9)
				dp_result[i % 2][j] = dp_result[(i - 1) % 2][j - 1] % DIV;
			else
				dp_result[i % 2][j] = (dp_result[(i - 1) % 2][j - 1] + dp_result[(i - 1) % 2][j + 1]) % DIV;
		}
	}

	/* PRINT result */
	int sum = 0;
	for (int j = 0; j <= 9; j++)
	{
		sum += dp_result[N % 2][j];

		sum = sum % DIV;
	}
	cout << sum;

	return 0;
}
