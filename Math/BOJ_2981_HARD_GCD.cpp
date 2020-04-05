#include <iostream>

using namespace std;

int GCD_stable(const int& a, const int& b)
{
	if (b == 0)
		return a;
	else
		return GCD_stable(b, a % b);
}

int GCD(const int &a, const int &b)
{
	int temp_max;
	int temp_min;

	if (a > b)
	{
		temp_max = a;
		temp_min = b;
	}
	else
	{
		temp_max = b;
		temp_min = a;
	}
	
	if (temp_min == 0)
		return temp_max;
	else
		return GCD_stable(temp_min, temp_max % temp_min);
}

/* BOJ 2981 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int minn = 1000000001;

	/* USER INPUT */
	cin >> N;

	int* M = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> M[i];

		if (M[i] < minn)
			minn = M[i];
	}

	bool* answer = new bool[minn+1];

	/* Processing */
	int result;

	for (int remain = 0; remain <= minn; remain++)
	{
		result = GCD(M[0]-remain, M[1]-remain);

		for (int i = 2; i < N; i++)
		{
			result = GCD(result, M[i]-remain);
		}

		if (result > 1)
			answer[result] = true;
	}

	/* PRINT RESULT */
	for (int i = 2; i <= minn; i++)
	{
		if (answer[i] == true)
			cout << i << " ";
	}

	return 0;
}
