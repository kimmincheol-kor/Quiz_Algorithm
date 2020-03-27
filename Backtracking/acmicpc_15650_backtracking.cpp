#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int cnt;
int arr_num[9];
bool visited[9];

void tracking(int idx)
{
	if (idx == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr_num[i] << " ";
		cout << "\n";

		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			arr_num[idx] = i;
			visited[i] = true;
			tracking(idx + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	tracking(0);
	
	return 0;
}