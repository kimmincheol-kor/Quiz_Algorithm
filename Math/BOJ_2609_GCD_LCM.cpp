#include <iostream>

using namespace std;

/* BOJ 2609 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	int min_num;

	/* USER INPUT */
	cin >> N >> M;

	min_num = N < M ? N : M;
	
	/* Processing */
	// GCD
	for (int i = min_num; i > 0; i--)
	{
		if (N % i == 0 && M % i == 0)
		{
			cout << i << "\n";
			break;
		}
	}

	// LCM
	for (int i = 1; i <= N*M; i++)
	{
		if (i%N == 0 && i%M == 0)
		{
			cout << i;
			break;
		}
	}
	
	/* PRINT RESULT */
	
	return 0;
}
