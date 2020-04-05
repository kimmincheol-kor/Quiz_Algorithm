#include <iostream>

using namespace std;

int GCD(int maxx, int minn)
{
	if (minn == 0)
		return maxx;
	else
		return GCD(minn, maxx%minn);
}

/* BOJ 2609 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	int min_, max_;

	/* USER INPUT */
	cin >> N >> M;

	if (N < M)
	{
		min_ = N;
		max_ = M;
	}
	else
	{
		min_ = M;
		max_ = N;
	}

	/* Processing */
	// GCD
	int gcd = GCD(max_, min_);

	// LCM
	int lcm = N * M / gcd;

	/* PRINT RESULT */
	cout << gcd << "\n" << lcm;

	return 0;
}
