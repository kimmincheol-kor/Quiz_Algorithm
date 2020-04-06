#include <iostream>

using namespace std;

int GCD(const int &a, const int &b)
{
	int minn, maxx;

	if (a < b)
	{
		minn = a;
		maxx = b;
	}
	else
	{
		minn = b;
		maxx = a;
	}

	if (minn == 0)
		return maxx;
	else
		return GCD(b, a%b);

}

/* BOJ 3036 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int ring[100];
	
	/* USER INPUT */
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> ring[i];

	/* Processing */
	for (int i = 1; i < N; i++)
	{
		int gcd = GCD(ring[0], ring[i]);

		cout << ring[0] / gcd << "/" << ring[i] / gcd << "\n";
	}

	/* PRINT RESULT */


	return 0;
}
