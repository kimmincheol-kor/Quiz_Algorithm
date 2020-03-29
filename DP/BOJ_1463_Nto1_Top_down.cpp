#include <iostream>

using namespace std;

int N;

int cmp_min(int x, int y, int z)
{
	if (x == 0)
		x = 1000000000;
	if (y == 0)
		y = 1000000000;
	if (z == 0)
		z = 1000000000;

	return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

/* BOJ 1463 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* USER INPUT */
	cin >> N;

	if (N < 4)
	{
		cout << N / 2;
		return 0;
	}

	int* cnt[3];
	for (int i = 0; i < 3; i++)
		cnt[i] = new int[N + 1];

	if (N % 3 == 0)
		cnt[0][1] = N / 3;
	else
		cnt[0][1] = 0;

	if (N % 2 == 0)
		cnt[1][1] = N / 2;
	else
		cnt[1][1] = 0;

	cnt[2][1] = N - 1;

	for (int i = 2; i <= N; i++)
	{
		int temp[10];
		for (int j = 1; j < 10; j++)
			temp[j] = 0;

		if (cnt[0][i - 1] > 1)
		{
			if (cnt[0][i - 1] % 3 == 0)
				temp[1] = cnt[0][i - 1] / 3;

			if (cnt[0][i - 1] % 2 == 0)
				temp[2] = cnt[0][i - 1] / 2;

			temp[3] = cnt[0][i - 1] - 1;
		}

		if (cnt[1][i - 1] > 1)
		{
			if (cnt[1][i - 1] % 3 == 0)
				temp[4] = cnt[1][i - 1] / 3;

			if (cnt[1][i - 1] % 2 == 0)
				temp[5] = cnt[1][i - 1] / 2;

			temp[6] = cnt[1][i - 1] - 1;
		}

		if (cnt[2][i - 1] > 1)
		{
			if (cnt[2][i - 1] % 3 == 0)
				temp[7] = cnt[2][i - 1] / 3;

			if (cnt[2][i - 1] % 2 == 0)
				temp[8] = cnt[2][i - 1] / 2;

			temp[9] = cnt[2][i - 1] - 1;
		}

		cnt[0][i] = cmp_min(temp[1], temp[4], temp[7]);
		cnt[1][i] = cmp_min(temp[2], temp[5], temp[8]);
		cnt[2][i] = cmp_min(temp[3], temp[6], temp[9]);

		if (cnt[0][i] == 1 || cnt[1][i] == 1 || cnt[2][i] == 1)
		{
			cout << i;
			break;
		}
	}

	return 0;
}
