#include <iostream>

using namespace std;

/* BOJ 11047 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, V;

	/* USER INPUT */
	cin >> N >> V;

	int * list_coin = new int[N];
	int cnt_coin = 0;

	for (int i = 0; i < N; i++)
		cin >> list_coin[i];

	/* Processing */
	for (int i = 1; i <= N; i++)
	{
		if (list_coin[N - i] <= V)
		{
			int cnt = V / list_coin[N - i];
			V -= cnt * list_coin[N - i];
			cnt_coin += cnt;
		}

		if (V <= 0)
			break;
	}

	/* PRINT RESULT */
	cout << cnt_coin;

	return 0;
}
