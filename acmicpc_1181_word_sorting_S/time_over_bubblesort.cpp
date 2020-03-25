#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;

// vecter for store words.
vector <string> words;

// compare function.
bool cmp_word(string a, string b)
{
	char temp_a, temp_b; // use to compare one character

	// compare size.
	if (a.size() > b.size())
		return true;
	else if (a.size() < b.size())
		return false;
	
	// min between a.size , b.size
	int min = a.size() > b.size() ? b.size() : a.size();

	// compare characters
	for (int i = 0; i < min; i++)
	{
		temp_a = a[i];
		temp_b = b[i];

		if (temp_a > temp_b)
			return true;
		else if (temp_a < temp_b)
			return false;
	}
}

// bubble sort. (String)
void bubble_sort()
{
	for (int i = N-1; i > 0; i--) // total cycle.
	{
		for (int j = 0; j < i; j++) // one cycle.
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

	// user input.
	for (int i = 0; i < N; i++)
	{
		cin >> input_data;

		words.push_back(input_data);
	}

	// sorting.
	bubble_sort();

	// print
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