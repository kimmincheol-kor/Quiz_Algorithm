#include <iostream>
#include <vector>

using namespace std;

int N;	// number of player

int ability[21][21];	// store user input.

bool visited[21];	// Use to check visited

int min_gap = 1000;

/* Check gap point between two teams. */
void check_gap()
{
	int ability_start = 0;	// start team's ability
	int ability_link = 0;	// link team's ability

	vector<int> team_link;
	vector<int> team_start;

	/* make two teams. */
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == false)
			team_link.push_back(i);
		else
			team_start.push_back(i);
	}

	/* calculate ability point. */
	for (int i = 0; i < N / 2; i++)
	{
		for (int j = 0; j < N / 2; j++)
		{
			if (i != j)
			{
				ability_start += ability[team_start[i]][team_start[j]];
				ability_link += ability[team_link[i]][team_link[j]];
			}
		}
	}

	/* calculatate gap */
	int gap = ability_start - ability_link;

	if (gap < 0)
		gap *= -1;

	/* Is that min ? */
	if (gap < min_gap)
		min_gap = gap;
}

/* Function for Calculate minimum gap between two teams. */
void run(int num_needs, int start)
{
	if (num_needs == 0)	// start team has full member
	{
		check_gap();

		return;
	}

	/* Test the all of case */
	for (int i = start; i <= N; i++)
	{
		if (visited[i] == false)	// is that none team player ?
		{
			visited[i] = true;

			run(num_needs - 1, i+1);	// pick next player.

			/* make 108ms -> 12ms */
			if (min_gap == 0)
				return;

			visited[i] = false;
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
	run(N / 2, 1);

	cout << min_gap;
	
	return 0;
}