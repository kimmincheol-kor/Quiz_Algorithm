#include <iostream>

using namespace std;

int N;

int cmp_max(int x, int y)
{
	return x > y ? x : y;
}

/* BOJ 2579 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int* sum[3];
	for (int i = 0; i < 3; i++)
		sum[i] = new int[N + 1];

	int max_sum = 0;

	/* USER INPUT */
	for (int i = 1; i <= N; i++)
	{
		cin >> sum[0][i];
	}

	sum[1][1] = sum[0][1];
	sum[2][1] = sum[0][1];

	sum[1][2] = sum[0][2] + sum[1][1];
	sum[2][2] = sum[0][2];

	/* Processing */
	for (int i = 3; i <= N; i++) // floor
	{
		sum[1][i] = sum[2][i-1] + sum[0][i];
		sum[2][i] = cmp_max(sum[1][i-2], sum[2][i-2]) + sum[0][i];
	}
	
	/* Find Max Value */
	max_sum = cmp_max(sum[1][N], sum[2][N]);
	
	cout << max_sum;

	return 0;
}
