#include <iostream>
#include <vector>

using namespace std;

int N;	// number of player

int ability[21][21];	// store user input.

bool visited[21];	// Use to check visited

vector<int> team_start;

int min_gap = 1000;

/* Check gap point between two teams. */
void check_gap()
{
	int ability_start = 0;	// start team's ability
	int ability_link = 0;	// link team's ability

	vector<int> team_link;

	/* make link team. */
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == false)
			team_link.push_back(i);
	}

	/* calculate ability point. */
	for (int i = 0; i < N / 2; i++)
	{
		int mem_start = team_start[i];
		int mem_link = team_link[i];

		for (int j = 0; j < N / 2; j++)
		{
			if (i != j)
			{
				ability_start += ability[mem_start][team_start[j]];
				ability_link += ability[mem_link][team_link[j]];
			}
		}
	}

	/* calculatate gap */
	int gap;

	if (ability_start > ability_link)
		gap = ability_start - ability_link;
	else
		gap = ability_link - ability_start;

	/* Is that min ? */
	if (gap < min_gap)
		min_gap = gap;
}

/* Function for Calculate minimum gap between two teams. */
void run(int num_needs)
{
	if (num_needs == 0)	// start team has full member
	{
		check_gap();

		return;
	}

	/* Test the all of case */
	for (int i = 1; i <= N; i++)
	{
		bool flag = false;

		if (num_needs == N / 2)
			flag = true;
		else if (i > team_start.back())
			flag = true;

		if (visited[i] == false && flag == true)	// is that none team player ?
		{
			visited[i] = true;
			team_start.push_back(i);	// push to start team.

			run(num_needs - 1);	// pick next player.

			visited[i] = false;
			team_start.pop_back();
		}
	}
}

/* BOJ 14889 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	/* user input : Score Chart */
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> ability[i][j];
		}
	}

	/* Run */
	run(N / 2);

	cout << min_gap;
	
	return 0;
}