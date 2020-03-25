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

void quick_sort(int start, int end)
{
	if (start == end)
		return;

	string pivot = words[start];

	vector<string> left_;
	vector<string> right_;

	int position = start;

	for (int i = start + 1; i <= end; i++)
	{
		if (cmp_word(pivot, words[i]) == true)
		{
			left_.push_back(words[i]);
			position++;
		}
		else
			right_.push_back(words[i]);
	}

	int iter_l = 0;
	int iter_r = 0;

	// swap.
	for (int i = start; i <= end; i++)
	{
		if (i < position)
			words[i] = left_[iter_l++];
		else if (i > position)
			words[i] = right_[iter_r++];
		else
			words[i] = pivot;
	}

	if (position > start && position < end)
	{
		quick_sort(start, position - 1);
		quick_sort(position + 1, end);
	}
	else if (position == end)
		quick_sort(start, position - 1);
	else if (position == start)
		quick_sort(start + 1, end);
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

	quick_sort(0, N - 1);

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