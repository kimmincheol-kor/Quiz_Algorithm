#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, int>>* adj_list;			// adjency list
vector<pair<int, pair<int, int>>> all_list; // all edge list
int* prim;

bool cmp_edge(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	return a.second.second < b.second.second;
}

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

	adj_list = new vector<pair<int, int>>[N+1];
	prim = new int[N + 1];
	for (int i = 1; i < N + 1; i++)
		prim[i] = 10001;

	// input edge.
	for (int i = 0; i < M; i++) {
		cin >> input1 >> input2 >> input3;

		all_list.push_back(make_pair(input1, make_pair(input2, input3)));
	}

	/* Processing */

	// sort edge list
	sort(all_list.begin(), all_list.end(), cmp_edge);

	// edge list -> adjency list
	for (int i = 0; i < M; i++) {
		adj_list[all_list[i].first].push_back(all_list[i].second);
		adj_list[all_list[i].second.first].push_back(make_pair(all_list[i].first, all_list[i].second.second));
	}

	int iterator;
	int pre_node[1001];
	for (int i = 1; i < N + 1; i++)
		pre_node[i] = -1;
	bool visited[1001];
	for (int i = 1; i < N + 1; i++)
		visited[i] = false;

	// Prim's Algorithm
	queue<int> s;
	s.push(1);
	prim[1] = 0;

	while (1)
	{
		if (s.empty()) // queue is empty -> Exit
			break;

		// pop from queue
		iterator = s.front();
		s.pop();
		visited[iterator] = true;

		// update prim
		for (int i = 0; i < adj_list[iterator].size(); i++)
		{
			// Exception.
			if (pre_node[iterator] == adj_list[iterator][i].first)
				continue;

			// Need Update.
			if (prim[adj_list[iterator][i].first] > adj_list[iterator][i].second)
			{
				pre_node[adj_list[iterator][i].first] = iterator;
				prim[adj_list[iterator][i].first] = adj_list[iterator][i].second;
			}

			// New Node.
			if (visited[adj_list[iterator][i].first] == false)
				s.push(adj_list[iterator][i].first);
		}
	}
	
	/* PRINT RESULT */
	for (int i = 1; i < N + 1; i++)
		result += prim[i];

	cout << result;

	return 0;
}