#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>

using namespace std;

int N, M;
vector<int>* adj_list;
int uni[1001];

bool cmp_start(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
	return a.first.first < b.first.first;
}

bool cmp_edge(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
	return a.second < b.second;
}

bool union_find(int p1, int p2);

/* BOJ 1922 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input1, input2, input3;
	int cnt = 1;
	int result = 0;

	/* USER INPUT */
	cin >> N;
	cin >> M;

	vector<pair<pair<int, int>, int>> all_list;
	pair<pair<int, int>, int> tmp_pair;

	adj_list = new vector<int>[N + 1];

	// Input
	for (int i = 0; i < M; i++)
	{
		cin >> input1 >> input2 >> input3;

		tmp_pair = make_pair(make_pair(input1, input2), input3);
		all_list.push_back(tmp_pair);
	}

	/* Processing */
	// initializing union set
	for (int i = 1; i < N + 1; i++)
		uni[i] = i;

	// Kruskals
	sort(all_list.begin(), all_list.end(), cmp_edge);

	int node1, node2;
	for (int i = 0; i < all_list.size(); i++)
	{
		// Cur Edge : node1 -> node2
		node1 = all_list[i].first.first;
		node2 = all_list[i].first.second;

		// Check Cycle : Union Find
		if (union_find(node1, node2))
		{
			result += all_list[i].second;

			// Check End of Process
			if (cnt == N - 1)
				break;
			else
				cnt++;
		}
	}

	/* PRINT RESULT */
	cout << result;

	return 0;
}

bool union_find(int p1, int p2)
{
	int new_uni;
	int target_uni;

	if (uni[p1] == uni[p2]) // cycle !!
		return false;
	else // no cycle
	{
		if (uni[p1] < uni[p2])
		{
			new_uni = uni[p1];
			target_uni = uni[p2];
		}
		else
		{
			new_uni = uni[p2];
			target_uni = uni[p1];
		}
	}

	// union refactoring
	for (int i = 1; i < N + 1; i++)
	{
		if (uni[i] == target_uni)
		{
			uni[i] = new_uni;
		}
	}

	return true;
}