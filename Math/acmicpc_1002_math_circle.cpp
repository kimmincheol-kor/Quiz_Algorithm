#define _USE_MATH_DEFINES

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int T;
int x_1;
int x_2;
int y_1;
int y_2;
int r_1;
int r_2;

long long distance_point;
long long r_sum;
long long r_sub;

int result[1000001];
int cnt = 0;

// Run
void run()
{
	if (distance_point == 0 && r_sub == 0) // same one.
		result[cnt++] = -1;
	else if (distance_point == r_sub || distance_point == r_sum) // one touch.
		result[cnt++] = 1;
	else if (distance_point < r_sub || distance_point > r_sum) // no touch
		result[cnt++] = 0;
	else // two touch.
		result[cnt++] = 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;

		r_sum = (long long)r_1 + (long long)r_2;
		r_sum *= r_sum;
		r_sub = r_1 > r_2 ? (long long)r_1 - (long long)r_2 : (long long)r_2 - (long long)r_1;
		r_sub *= r_sub;

		distance_point = ((long long)x_1 - (long long)x_2) * ((long long)x_1 - (long long)x_2) + ((long long)y_1 - (long long)y_2) * ((long long)y_1 - (long long)y_2);

		run();
	}

	for (int i = 0; i < T; i++)
		cout << result[i] << "\n";

	return 0;
}