#include <iostream>

using namespace std;

int N;

/* BOJ 11054 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int* list = new int[N];
	int* dp_up = new int[N];
	int* dp_down = new int[N];
	
	/* USER INPUT */
	for (int i = 0; i < N; i++)
		cin >> list[i];

	/* Processing */
	// Up
	dp_up[0] = 1;
	int max_value = 0;

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (dp_up[j] > max_value && list[j] < list[i])
				max_value = dp_up[j];
		}

		dp_up[i] = max_value + 1;
		max_value = 0;
	}

	//Down
	dp_down[N-1] = 1;

	for (int i = N - 2; i >= 0; i--)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (dp_down[j] > max_value && list[j] < list[i])
				max_value = dp_down[j];
		}

		dp_down[i] = max_value + 1;
		max_value = 0;
	}

	/* Find MAX */
	for (int i = 0; i < N; i++)
	{
		if (dp_up[i] + dp_down[i] > max_value)
			max_value = dp_up[i] + dp_down[i];
	}

	cout << max_value - 1;

	return 0;
}
