#include <iostream>
#include <vector>

using namespace std;

int N;

int sum = 0;
int min_sum = 1000000;

int* rgb[3];

bool visited[3];

/* DFS, DP */
void dfs(int n)
{
	if (sum > min_sum)
		return;

	if (n == N)
	{
		if (sum < min_sum)
			min_sum = sum;

		return;
	}

	int k;

	for (int i = 0; i < 3; i++)
	{
		if (visited[i] == false)
		{
			for (k = 0; k < 3; k++)
			{
				if (visited[k] == true)
					visited[k] = false;
			}

			visited[i] = true;
			sum += rgb[i][n];

			dfs(n + 1);

			sum -= rgb[i][n];
			visited[i] = false;

			visited[k] = true;
		}
	}
}

/* BOJ 1149 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < 3; i++)
		rgb[i] = new int[N];
	
	/* USER INPUT */
	for (int i = 0; i < N; i++)
		cin >> rgb[0][i] >> rgb[1][i] >> rgb[2][i];

	dfs(0);

	cout << min_sum << "\n";

	return 0;
}
