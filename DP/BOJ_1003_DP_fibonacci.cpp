#include <iostream>
#include <vector>

using namespace std;

int T, N;

int dp_0[41];
int dp_1[41];

/* BOJ 1003 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> result;

	cin >> T;

	vector<int> input;

	/* USER INPUT */
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		input.push_back(N);
	}

	dp_0[0] = 1;
	dp_0[1] = 0;

	dp_1[0] = 0;
	dp_1[1] = 1;

	/* OPERATE AND PRINT */
	for (int i = 0; i < T; i++)
	{
		if (input[i] > 1 && (dp_0[input[i]] == 0 || dp_1[input[i]] == 0))
		{
			for (int k = 2; k <= input[i]; k++)
			{
				if (dp_0[k] == 0)
				{
					dp_0[k] = dp_0[k - 1] + dp_0[k - 2];
					dp_1[k] = dp_1[k - 1] + dp_1[k - 2];
				}
				else
					continue;
			}
		}

		cout << dp_0[input[i]] << " " << dp_1[input[i]] << "\n";
	}

	return 0;
}
