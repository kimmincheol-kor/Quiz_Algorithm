#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int T, N;
int max_num = 0;

bool is_prime[1000001];

queue <int> result;

// Run
void run(int n)
{
	int first = n/2;
	int second = n/2;

	while (1)
	{
		if (is_prime[first] != true && is_prime[second] != true) // both are not true
		{
			first--;
			second++;
		}
		else if (is_prime[first] != true) // first number is not true.
			first--;
		else if (is_prime[second] != true) // second number is not true.
			second++;
		else // both are true
		{
			int sum = first + second;

			if (sum < n)
				second++;
			else if (sum > n)
				first--;
			else
			{
				cout << first << " " << second << "\n";
				return;
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(is_prime, true, sizeof(is_prime));

	int* arr;

	cin >> T;

	arr = new int[T];

	for (int i = 0; i < T; i++) // input array.
	{
		cin >> arr[i];

		if (arr[i] > max_num)
			max_num = arr[i];
	}

	is_prime[1] = false;

	for (long long i = 2; i <= max_num; i++) // find all 2~max_num
	{
		if (is_prime[i] == true) // if this is prime,
		{
			if (i * i > max_num) // need break.
				break;

			for (long long k = 0; ; k++) // check prime.
			{
				if ((i * i) + (i * k) > max_num) // need break.
					break;

				is_prime[(i * i) + (i * k)] = false;
			}
		}
	}

	// run
	for (int i = 0; i < T; i++)
		run(arr[i]);

	return 0;
}