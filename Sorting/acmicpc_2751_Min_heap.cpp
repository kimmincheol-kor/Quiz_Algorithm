#include <iostream>
#include <vector>

#define LEFT(i) i*2
#define RIGHT(i) i*2+1
#define PARENT(i) i/2

using namespace std;

int N;

class Heap_min
{
public :
	vector <int> list;
	int cnt = 0;

	void push(int new_data)
	{
		int cur_position;

		list.push_back(new_data);
		cnt++;
		
		cur_position = cnt;

		while (cur_position > 1)
		{
			if (list[PARENT(cur_position)] > list[cur_position])
			{
				int temp = list[cur_position];
				list[cur_position] = list[PARENT(cur_position)];
				list[PARENT(cur_position)] = temp;

				cur_position = PARENT(cur_position);
			}
			else
				break;
		}
	}

	int pop()
	{
		int cur_position = 1;

		// swap
		int result = list[1];
		list[1] = list[cnt];
		list[cnt] = result;

		// pop
		list.pop_back();
		cnt--;

		while (1)
		{
			if (LEFT(cur_position) <= cnt && RIGHT(cur_position) <= cnt) // exist LEFT, RIGHT
			{
				if (list[LEFT(cur_position)] < list[RIGHT(cur_position)]) // LEFT < RIGHT
				{
					if (list[LEFT(cur_position)] < list[cur_position])
					{
						int temp = list[cur_position];
						list[cur_position] = list[LEFT(cur_position)];
						list[LEFT(cur_position)] = temp;

						cur_position = LEFT(cur_position);
					}
					else
						break;
				}
				else // LEFT > RIGHT
				{
					if (list[RIGHT(cur_position)] < list[cur_position])
					{
						int temp = list[cur_position];
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
				if (list[LEFT(cur_position)] < list[cur_position]) // LEFT < RIGHT
				{
					int temp = list[cur_position];
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

	Heap_min my_heap;
	my_heap.list.push_back(0);

	int input_value;

	for (int i = 0; i < N; i++)
	{
		cin >> input_value;
		my_heap.push(input_value);
	}

	for (int i = 0; i < N; i++)
		cout << my_heap.pop() << "\n";
	
	return 0;
}