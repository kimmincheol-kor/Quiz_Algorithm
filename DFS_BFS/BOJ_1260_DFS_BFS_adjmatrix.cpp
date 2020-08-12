#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int N, M, V;
bool** adj_matrix;

void DFS();
void BFS();

/* BOJ 1260 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input1, input2;

	/* USER INPUT */
	cin >> N >> M >> V;

	// Dynamic Allocation
	adj_matrix = new bool*[N];
	for (int i = 0; i < N; i++)
	{
		adj_matrix[i] = new bool[N];

		// initializing
		for (int j = 0; j < N; j++)
			adj_matrix[i][j] = false;
	}

	// Input
	for (int i = 0; i < M; i++)
	{
		cin >> input1 >> input2;

		adj_matrix[input1 - 1][input2 - 1] = true;
		adj_matrix[input2 - 1][input1 - 1] = true;
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
	for (int i = 0; i < N; i++)
		visited[i] = false;

	// Start Node.
	stack1.push(V-1);

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
			cout << iterator + 1 << " ";
		}

		// Find Adjacency Node
		for (int i = N - 1; i >= 0; i--)
		{
			if (adj_matrix[iterator][i] == true && visited[i] == false)
			{
				stack1.push(i);
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
	for (int i = 0; i < N; i++)
		visited[i] = false;

	// Start Node.
	queue1.push(V - 1);

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
			cout << iterator + 1 << " ";
		}

		// Find Adjacency Node
		for (int i = 0; i < N; i++)
		{
			if (adj_matrix[iterator][i] == true && visited[i] == false)
				queue1.push(i);
		}
	}

	cout << "\n";
	return;
}
