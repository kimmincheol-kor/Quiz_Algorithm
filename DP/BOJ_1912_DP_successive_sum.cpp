#include <iostream>

using namespace std;

int N;

/* BOJ 1912 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* USER INPUT */
	cin >> N;
	
	int* list = new int[N];
	int* dp = new int[N];

	for (int i = 0; i < N; i++)
		cin >> list[i];

	/* Processing */
	dp[0] = list[0];
	int num_pass = 0;

	for (int i = 1; i < N; i++)
	{
		if (list[i] >= 0) // cur value is 0+
		{
			if(num_pass == 0)				// successive now.
				dp[i] = list[i] + dp[i - 1];
			else							// not successive now.
			{
				int temp = 0;

				int pass_sum = 0;
				int max_sum = 0;

				// calculate passed numbers.
				for (int k = i - num_pass; k <= i; k++)
				{
					temp = 0;

					for (int a = k; a <= i; a++)
						temp += list[a];

					if (k == i - num_pass)
						pass_sum = temp;
					if (temp > max_sum)
						max_sum = temp;
				}

				// compare.
				if (pass_sum > 0 && pass_sum + dp[i-1] > max_sum)
				{
					dp[i] = dp[i - 1] + pass_sum;
					num_pass = 0;
				}
				else 
				{
					if (dp[i - 1] < max_sum)
					{
						dp[i] = max_sum;
						num_pass = 0;
					}
					else
					{
						dp[i] = dp[i - 1];
						num_pass += 1;
					}
				}
			}
		}
		else // cur value is 0-
		{
			dp[i] = dp[i - 1];
			num_pass += 1;
		}
	}

	/* PRINT RESULT */
	cout << dp[N - 1];

	return 0;
}
