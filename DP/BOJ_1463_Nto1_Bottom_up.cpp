#include <iostream>

using namespace std;

int N;

int cmp_min(int x, int y, int z)
{
	return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

/* BOJ 1463 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* USER INPUT */
	cin >> N;

	/* Processing */
	int * dp_result = new int[N+1];

	dp_result[0] = 0;
	dp_result[1] = 0;
	dp_result[2] = 1;
	dp_result[3] = 1;

	for (int i = 4; i <= N; i++)
	{
		int div_3 = 1000001;
		int div_2 = 1000001;
		int sub_1 = 1000001;

		if (i % 3 == 0)
			div_3 = dp_result[i / 3] + 1;
		
		if (i % 2 == 0)
			div_2 = dp_result[i / 2] + 1;
		
		sub_1 = dp_result[i - 1] + 1;

		dp_result[i] = cmp_min(div_3, div_2, sub_1);
	}

	/* PRINT result */
	cout << dp_result[N];

	return 0;
}
