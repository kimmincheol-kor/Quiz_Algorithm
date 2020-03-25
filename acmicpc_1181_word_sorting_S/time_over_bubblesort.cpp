#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;

vector <string> words;

bool cmp_word(string a, string b)
{
	char temp_a, temp_b;

	if (a.size() > b.size())
		return true;
	else if (a.size() < b.size())
		return false;
	
	int min = a.size() > b.size() ? b.size() : a.size();

	for (int i = 0; i < min; i++)
	{
		temp_a = a[i];
		temp_b = b[i];

		if (temp_a > temp_b)
			return true;
		else if (temp_a < temp_b)
			return false;
	}

	if (min == a.size())
		return false;
	else
		return true;
}

void bubble_sort()
{
	int cur_index = 0;

	for (int i = N-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (cmp_word(words[j], words[j + 1]) == true)
			{
				// swap
				string temp = words[j];
				words[j] = words[j + 1];
				words[j + 1] = temp;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	string input_data;

	for (int i = 0; i < N; i++)
	{
		cin >> input_data;

		words.push_back(input_data);
	}

	bubble_sort();

	string pre_word;

	cout << words[0] << "\n";
	pre_word = words[0];

	for (int i = 0; i < N; i++)
	{
		if(pre_word != words[i])
			cout << words[i] << "\n";

		pre_word = words[i];
	}
	
	return 0;
}