#include <iostream>
#include <cmath>

using namespace std;

int N;

int counting_plus[4001];
int counting_minus[4001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input N.
	cin >> N;

	int* list = new int[N];
	int* result = new int[N];

	int sum = 0;

	// initialize count
	for (int i = 0; i < 4001; i++)
	{
		counting_plus[i] = 0;
		counting_minus[i] = 0;
	}

	// input.
	for (int i = 0; i < N; i++)
	{
		// input.
		cin >> list[i];
		result[i] = 0;

		// for math.
		sum += list[i];

		if (list[i] < 0) // minus
			counting_minus[list[i] * -1]++;
		else // plus
			counting_plus[list[i]]++;
	}

	// sort.
	int cnt = 0;
	int max_mode=0;
	int max_mode_index;

	bool same_mode = false;

	for (int i = 4000; i > 0; i--) // minus -4000~-1
	{
		if (counting_minus[i] > 0)
		{
			// for max_mode.
			if (counting_minus[i] > max_mode)
			{
				max_mode = counting_minus[i];
				max_mode_index = 0 - i;
				same_mode = false;
			}
			else if (counting_minus[i] == max_mode && same_mode == false)
			{
				max_mode_index = 0 - i;
				same_mode = true;
			}

			// make result.
			while (counting_minus[i] > 0)
			{
				result[cnt++] = 0 - i;
				counting_minus[i]--;
			}
		}
	}
	for (int i = 0; i < 4001; i++) // plus 0~4000
	{
		if (counting_plus[i] > 0)
		{
			// for max_mode.
			if (counting_plus[i] > max_mode)
			{
				max_mode = counting_plus[i];
				max_mode_index = i;
				same_mode = false;
			}
			else if (counting_plus[i] == max_mode && same_mode == false)
			{
				max_mode_index = i;
				same_mode = true;
			}

			// make result.
			while (counting_plus[i] > 0)
			{
				result[cnt++] = i;
				counting_plus[i]--;
			}
		}
	}

	// average.
	cout << round((double)sum / (double)N) << "\n";

	// median.
	cout << result[(N + 1) / 2 - 1] << "\n";

	// max mode.
	cout << max_mode_index << "\n";

	// range
	cout << result[N - 1] - result[0];

	return 0;
}