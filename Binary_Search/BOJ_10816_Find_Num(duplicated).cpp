#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> og_list;

/* BOJ 10816 */
int main() {
	int N, M;
	int temp;

	vector<int>::iterator low;
	vector<int>::iterator high;

	/* USER INPUT */
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		og_list.push_back(temp);
	}

	sort(og_list.begin(), og_list.end());

	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &temp);

		low = lower_bound(og_list.begin(), og_list.end(), temp);
		high = lower_bound(og_list.begin(), og_list.end(), temp + 1);

		printf("%ld ", high - low);
	}

	/* Processing */
	/* PRINT RESULT */

	return 0;
}
