#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, V;
vector<int>* adj_list;
vector<pair<int, int>> all_list;

void DFS();
void BFS();

bool cmp_all(pair<int, int> a, pair<int, int> b)
{
	if (a.first != b.first)
		return a.first < b.first;
	else
		return a.second < b.second;
}

/* BOJ 1260 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input1, input2;

	/* USER INPUT */
	cin >> N >> M >> V;

	// Dynamic Allocation
	adj_list = new vector<int> [N+1];

	// Input
	for (int i = 0; i < M; i++)
	{
		cin >> input1 >> input2;

		all_list.push_back(make_pair(input1, input2));
	}

	sort(all_list.begin(), all_list.end(), cmp_all);

	for (int i = 0; i < M; i++)
	{
		adj_list[all_list[i].first].push_back(all_list[i].second);
		adj_list[all_list[i].second].push_back(all_list[i].first);
	}

	/* Processing */
	DFS();
	BFS();

	/* PRINT RESULT */

	return 0;
}

void DFS() {
	stack<int> stack1;
	bool visited[1001];
	int iterator;

	// Initializing.
	for (int i = 0; i < N+1; i++)
		visited[i] = false;

	// Start Node.
	stack1.push(V);

	while (1)
	{
		if (stack1.empty())
			break;

		// Pop From Stack (Visiting)
		iterator = stack1.top();
		stack1.pop();

		if (visited[iterator] != true)
		{
			visited[iterator] = true;
			cout << iterator << " ";
		}

		// Find Adjacency Node
		for (int i = adj_list[iterator].size()-1; i >= 0; i--)
		{
			if (visited[adj_list[iterator][i]] == false)
			{
				stack1.push(adj_list[iterator][i]);
			}
		}
	}

	cout << "\n";
	return;
}

void BFS() {
	queue<int> queue1;
	bool visited[1001];
	int iterator;

	// Initializing.
	for (int i = 0; i < N+1; i++)
		visited[i] = false;

	// Start Node.
	queue1.push(V);

	while (1)
	{
		if (queue1.empty())
			break;

		// Pop From Queue (Visiting)
		iterator = queue1.front();
		queue1.pop();

		if (visited[iterator] != true)
		{
			visited[iterator] = true;
			cout << iterator << " ";
		}

		// Find Adjacency Node
		for (int i = 0; i < adj_list[iterator].size(); i++)
		{
			if (visited[adj_list[iterator][i]] == false)
				queue1.push(adj_list[iterator][i]);
		}
	}

	cout << "\n";
	return;
}