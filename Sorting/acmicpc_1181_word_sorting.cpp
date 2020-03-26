#include <iostream>
#include <string>
#include <vector>

#define LEFT(i) i*2
#define RIGHT(i) i*2+1
#define PARENT(i) i/2

using namespace std;

int N;

vector <string> words;

bool cmp_word(string a, string b)
{
	if (a.size() == b.size())
		return a > b;
	else
		return a.size() > b.size();
}

class Heap_min
{
public:
	vector <string> list;
	int cnt = 0;

	// Push Function.
	void push(string new_data)
	{
		int cur_position;

		list.push_back(new_data);
		cnt++;

		cur_position = cnt;

		while (cur_position > 1) // search Last -> First
		{
			if (cmp_word(list[PARENT(cur_position)], list[cur_position]) == true) // need swap.
			{
				string temp = list[cur_position];
				list[cur_position] = list[PARENT(cur_position)];
				list[PARENT(cur_position)] = temp;

				cur_position = PARENT(cur_position);
			}
			else // end of search
				break;
		}
	}

	// Pop Function.
	string pop()
	{
		int cur_position = 1;

		// swap
		string result = list[1];
		list[1] = list[cnt];
		list[cnt] = result;

		// pop
		list.pop_back();
		cnt--;

		while (1)
		{
			if (LEFT(cur_position) <= cnt && RIGHT(cur_position) <= cnt) // exist LEFT, RIGHT
			{
				if (cmp_word(list[LEFT(cur_position)], list[RIGHT(cur_position)]) == false) // LEFT < RIGHT
				{
					if (cmp_word(list[LEFT(cur_position)], list[cur_position]) == false)
					{
						string temp = list[cur_position];
						list[cur_position] = list[LEFT(cur_position)];
						list[LEFT(cur_position)] = temp;

						cur_position = LEFT(cur_position);
					}
					else
						break;
				}
				else // LEFT > RIGHT
				{
					if (cmp_word(list[RIGHT(cur_position)], list[cur_position]) == false)
					{
						string temp = list[cur_position];
						list[cur_position] = list[RIGHT(cur_position)];
						list[RIGHT(cur_position)] = temp;

						cur_position = RIGHT(cur_position);
					}
					else
						break;
				}


			}
			else if (LEFT(cur_position) <= cnt) // exist only LEFT
			{
				if (cmp_word(list[LEFT(cur_position)], list[cur_position]) == false) // LEFT < RIGHT
				{
					string temp = list[cur_position];
					list[cur_position] = list[LEFT(cur_position)];
					list[LEFT(cur_position)] = temp;
				}

				break;
			}
			else // none child
				break;
		}

		return result;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// make min heap.
	Heap_min my_heap;
	my_heap.list.push_back("0"); // element [0] = null.

	string input_data;

	// user input to min heap.
	for (int i = 0; i < N; i++)
	{
		cin >> input_data;

		my_heap.push(input_data);
	}

	// print
	string pre_word = my_heap.pop();

	cout << pre_word << "\n";

	for (int i = 1; i < N; i++)
	{
		string temp = my_heap.pop();

		if(pre_word != temp)
			cout << temp << "\n";

		pre_word = temp;
	}
	
	return 0;
}