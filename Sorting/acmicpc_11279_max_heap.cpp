#include <iostream>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

#define MAX(a,b) a > b ? 1 : 2

#define PARENT(n) n/2
#define LEFT(n) n*2
#define RIGHT(n) n*2+1
 
using namespace std;

int N;

int circular_queue[50];
int extract_num[50];

void swap(int &a, int&b )
{
	int temp;

	temp = a;

	a = b;
	b = temp;
}


class Heap
{
public:
	vector<int> tree;
	int last_num = 0;

	void push_data(int n)
	{
		tree.push_back(n);

		if (n == 0)
			return;

		last_num++;

		if (last_num == 1)
			return;

		int index = last_num;
	
		// sort
		while (1)
		{
			if (tree[index] > tree[PARENT(index)])
			{
				swap(tree[PARENT(index)], tree[index]);
				index = PARENT(index);

				if (index == 1)
					break;
			}
			else
				break;
		}
	}

	int pop_data()
	{
		if (last_num == 0)
			return 0;

		int index;
		int max_value;
		int larger;

		swap(tree[last_num], tree[1]);
		max_value = tree[last_num];
		tree.pop_back();
		last_num--;

		if (last_num == 0)
			return max_value;

		index = 1;

		// sort
		while (1)
		{
			if (LEFT(index) <= last_num && RIGHT(index) <= last_num)
				larger = MAX(tree[LEFT(index)], tree[RIGHT(index)]);
			else if (LEFT(index) <= last_num)
				larger = 1;
			else if (RIGHT(index) <= last_num)
				larger = 2;
			else
				break;

			if (larger == 1) // LEFT < RIGHT
			{
				if (tree[index] < tree[LEFT(index)])
				{
					swap(tree[LEFT(index)], tree[index]);
					index = LEFT(index);
				}
				else
					break;
			}
			else if (larger == 2) // RIGHT < LEFT
			{
				if (tree[index] < tree[RIGHT(index)])
				{
					swap(tree[RIGHT(index)], tree[index]);
					index = RIGHT(index);
				}
				else
					break;
			}
		}

		return max_value;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Heap my_heap;
	my_heap.tree.reserve(100000);

	int func;

	vector<int> result;

	my_heap.push_data(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> func;

		if (func == 0)
			result.push_back(my_heap.pop_data());
		else
			my_heap.push_data(func);
	}

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "\n";

	return 0;
}