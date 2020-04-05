#include <iostream>

using namespace std;

/* BOJ 2981 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int min_1 = 1000000001;
	int min_2 = 1000000002;

	/* USER INPUT */
	cin >> N;

	int* M = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> M[i];

		if (M[i] < min_1)
		{
			min_2 = min_1;
			min_1 = M[i];
		}
		else if(M[i] < min_2)
		{
			min_2 = M[i];
		}
	}

	/* Processing */
	for (int i = 2; i <= min_2-min_1; i++)
	{
		int test = M[0] % i;
		for (int j = 1; j < N; j++)
		{
			if (M[j] % i != test)
			{
				test = -1;
				break;
			}
		}

		if (test != -1)
			cout << i << " ";
	}
	
	/* PRINT RESULT */
	
	return 0;
}
