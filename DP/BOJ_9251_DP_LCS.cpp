#include <iostream>
#include <string.h>

using namespace std;

int N;
int dp[1001][1001];

int max_val(const int a, const int b)
{
	return a > b ? a : b;
}

/* BOJ 9251 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str1;
	string str2;

	/* USER INPUT */
	cin >> str1;
	cin >> str2;

	// reset array 'dp'
	memset(dp, 0, sizeof(dp));

	/* Processing */
	for (int i = 1; i <= str1.length(); i++)
	{
		for (int j = 1; j <= str2.length(); j++)
		{
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max_val(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	/* PRINT RESULT */
	cout << dp[str1.length()][str2.length()];

	return 0;
}
