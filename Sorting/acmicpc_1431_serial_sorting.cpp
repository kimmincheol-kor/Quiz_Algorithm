#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int getSum(string str)
{
	int sum = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] - '0' <= 9 && str[i] - '0' >= 0)
			sum += str[i] - '0';
	}

	return sum;
}

bool cmp_str(string str1, string str2)
{
	if (str1.length() != str2.length())
		return str1.length() < str2.length();
	else
	{
		// compare : Sum Of Number
		int sum1 = getSum(str1);
		int sum2 = getSum(str2);

		if (sum1 != sum2) // Sort by Sum
			return sum1 < sum2;
		else // Sort by Dictionary
			return str1 < str2;
	}
}

/* BOJ 1431 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> v_str;
	string temp_str;

	/* USER INPUT */
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp_str;

		v_str.push_back(temp_str);
	}

	/* Processing */
	sort(v_str.begin(), v_str.end(), cmp_str);

	/* PRINT RESULT */
	for (int i = 0; i < N; i++)
	{
		cout << v_str[i] << "\n";
	}

	return 0;
}