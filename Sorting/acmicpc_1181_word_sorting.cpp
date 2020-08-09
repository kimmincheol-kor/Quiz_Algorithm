#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool cmp_str(string str1, string str2)
{
	if (str1.length() != str2.length())
		return str1.length() < str2.length();
	else
		return str1 < str2;
}

/* BOJ 1181 */
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
	temp_str = v_str[0];
	cout << v_str[0] << "\n";

	for (int i = 1; i < N; i++)
	{
		if (temp_str != v_str[i])
		{
			temp_str = v_str[i];
			cout << v_str[i] << "\n";
		}
	}

	return 0;
}