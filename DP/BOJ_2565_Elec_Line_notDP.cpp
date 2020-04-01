#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int N;
int max_start = 0;

vector <int> v[501];

int line[501];
int num_cross[501];

int total_cross = 0;
int cnt_del = 0;

/* count cross */
void count_cross(int n)
{
	// larger number
	for (int i = max_start; i > n; i--)
	{
		if (line[i] == 0)
			continue;

		if (line[i] < line[n])
		{
			num_cross[n] += 1;
			num_cross[i] += 1;
			total_cross += 2;

			v[n].push_back(i);
			v[i].push_back(i);
		}
	}
}

/* Delete Line */
void del_line(int n)
{
	int num = num_cross[n];

	for (int i = 0; i < num; i++)
	{
		int temp = v[n].back();
		v[n].pop_back();
		
		if (num_cross[temp] != 0)
		{
			num_cross[n]--;
			num_cross[temp]--;
			total_cross -= 2;
		}
	}

	line[n] = 0;
	cnt_del += 1;
}

/* BOJ 2565 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int n_start, n_end;
	
	memset(line, 0, 501);
	memset(num_cross, 0, 501);
	
	/* USER INPUT */
	for (int i = 0; i < N; i++)
	{
		cin >> n_start >> n_end;

		if (n_start > max_start)
			max_start = n_start;
		
		line[n_start] = n_end;
	}

	/* Processing */
	for (int i = 1; i <= max_start; i++)
	{
		if (line[i] != 0)
			count_cross(i);
	}

	while (total_cross != 0)
	{
		// fine max
		int max_cross = 0;
		int max_index = 0;

		for (int i = 1; i <= max_start; i++)
		{
			if (max_cross < num_cross[i])
			{
				max_cross = num_cross[i];
				max_index = i;
			}
		}

		// del line
		del_line(max_index);
	}

	cout << cnt_del;

	return 0;
}
