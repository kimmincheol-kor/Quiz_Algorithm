#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int N;

// vector for store coordinates
vector<pair<int, int>> coordinates;

// compare pair data.
bool cmp_coordinate(pair<int, int> cd1, pair<int, int> cd2)
{
	// priority : first -> second.
	if (cd1.first > cd2.first)
		return true;
	else if (cd1.first < cd2.first)
		return false;
	else // first datas are same, compare second.
	{
		if (cd1.second > cd2.second)
			return true;
		else
			return false;
	}
}

// quick sort (pair<int, int>)
void quick_sort(int start, int end)
{
	if (start == end) // only one element -> exit.
		return;

	pair <int,int> pivot = coordinates[start]; // pivot = first element.

	// vecter for store left, right elements
	vector<pair<int, int>> left_;
	vector<pair<int, int>> right_;

	// position of pivot.
	int position = start;

	// compare and classify. Left, pivot, Right.
	for (int i = start+1; i <= end; i++)
	{
		if (cmp_coordinate(pivot, coordinates[i]) == true)
		{
			left_.push_back(coordinates[i]);
			position++;
		}
		else
			right_.push_back(coordinates[i]);
	}

	int iter_l = 0;
	int iter_r = 0;

	// Sorting
	for (int i = start; i <= end; i++)
	{
		if (i < position)
			coordinates[i] = left_[iter_l++];
		else if (i > position)
			coordinates[i] = right_[iter_r++];
		else
			coordinates[i] = pivot;
	}

	// recursion
	if (position > start && position < end)
	{
		quick_sort(start, position-1);
		quick_sort(position+1, end);
	}
	else if (position == end)
		quick_sort(start, position - 1);
	else if(position == start)
		quick_sort(start+1, end);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	pair<int, int> input_data;

	for (int i = 0; i < N; i++)
	{
		// user input
		cin >> input_data.first >> input_data.second;

		// push to vector
		coordinates.push_back(input_data);
	}

	// Sorting
	quick_sort(0, N-1);

	// Print
	for (int i = 0; i < N; i++)
		cout << coordinates[i].first << " " << coordinates[i].second << "\n";

	return 0;
}