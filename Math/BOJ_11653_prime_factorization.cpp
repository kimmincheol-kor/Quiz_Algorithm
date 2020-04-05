#include <iostream>

using namespace std;

/* BOJ 11653 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	
	/* USER INPUT */
	cin >> N;

	int* result = new int[N];
	int cnt = 0;

	/* Processing */
	while (N != 1)
	{
		for (int i = 2; i <= N; i++)
		{
			if (N % i == 0)
			{
				N /= i;
				cout << i << "\n";
				break;
			}
		}
	}

	/* PRINT RESULT */
	
	return 0;
}
