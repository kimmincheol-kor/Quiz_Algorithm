#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int idx = 0;
vector<int> og_list;
vector<int> result;

void bs(int num, int start, int end)
{
	int left = start;
	int right = end;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (og_list[mid] > num)
			right = mid - 1;
		else if (og_list[mid] < num)
			left = mid + 1;
		else
		{
			result[idx]++;

			for (int i = 1; i <= mid - start; i++)
				if (og_list[mid - i] == num)
					result[idx]++;
				else
					break;

			for (int i = 1; i <= end - mid; i++)
				if (og_list[mid + i] == num)
					result[idx]++;
				else
					break;

			return;
		}
	}
}

/* BOJ 10816 */
int main() {
	int N, M;
	int temp;

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
		result.push_back(0);

		bs(temp, 0, N - 1);
		printf("%d ", result[idx]);
		idx++;
	}

	/* Processing */
	/* PRINT RESULT */

	return 0;
}
