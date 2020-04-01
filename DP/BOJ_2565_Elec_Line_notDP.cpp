#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int N;

bool cmp_first(const pair<int, int> a, const pair<int, int> b)
{
	return a.first < b.first ? true : false;
}

/* BOJ 2565 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	pair<int, int>* line = new pair<int, int>[N];

	/* USER INPUT */
	for (int i = 0; i < N; i++)
		cin >> line[i].first >> line[i].second;

	/* Processing */
	// sorting
	sort(&line[0], &line[N], cmp_first);

	// LIS using vector
	vector <int> lis;
	lis.push_back(line[0].second);

	for (int i = 1; i < N; i++)
	{
		if (line[i].second > lis.back())			// increasing
			lis.push_back(line[i].second);
		else										// not increasing.
		{
			// find low bound
			for (int j = 0; j < lis.size(); j++)
			{
				if (lis[j] == line[i].second)
					break;
				else if (lis[j] > line[i].second)
				{
					lis[j] = line[i].second;
					break;
				}
			}
		}
	}

	/* PRINT RESULT */
	cout << N - lis.size();

	return 0;
}
