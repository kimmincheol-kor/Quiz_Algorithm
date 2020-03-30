#include <iostream>

using namespace std;

int N;

/* BOJ 11053 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int* list = new int[N];
	int* dp = new int[N];
	
	/* USER INPUT */
	for (int i = 0; i < N; i++)
		cin >> list[i];

	/* Processing */
	dp[0] = 1;
	int max_value = 0;

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (dp[j] > max_value && list[j] < list[i])
				max_value = dp[j];
		}

		dp[i] = max_value + 1;
		max_value = 0;
	}

	/* Find MAX */
	for (int i = 0; i < N; i++)
	{
		if (dp[i] > max_value)
			max_value = dp[i];
	}

	cout << max_value;

	return 0;
}
