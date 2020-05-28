#include <iostream>

using namespace std;

int N;

/* BOJ 1676 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int result = 1;
	int cnt = 0;

	/* USER INPUT */
	cin >> N;

	/* Processing */
  // Number of 0 = Number of 2*5=10
  // Number of 2 > Number of 5, So Find Number of 5
	cnt += N / 5 + N / 25 + N / 125;

	/* PRINT RESULT */
	cout << cnt;

	return 0;
}
