#include <iostream>
#include <vector>

using namespace std;

int N;

int counting[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int input_value;

	for (int i = 0; i < 10001; i++)
		counting[i] = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> input_value;
		counting[input_value]++;
	}

	int iter = 1;

	for (int i = 0; i < N; i++)
	{
		while (1)
		{
			if (counting[iter] != 0)
			{
				cout << iter << "\n";
				counting[iter]--;
				break;
			}
			else
				iter++;
		}
	}
	
	return 0;
}