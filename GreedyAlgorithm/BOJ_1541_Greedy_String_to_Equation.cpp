#include <iostream>
#include <string>
#include <stack>

using namespace std;

/* BOJ 1541 */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string equation;

	int num[30];
	char oper[30];

	int idx_num = 0;
	int idx_oper = 0;

	/* USER INPUT */
	cin >> equation;

	/* Processing */
	// classify operator and number.
	for (int i = 0; i < equation.length(); i++)
	{
		if (equation[i] < '0') // operator
		{
			// + : 0, - : 2
			oper[idx_oper++] = equation[i] - '+';
		}
		else // number
		{
			int cnt = 0;

			for (int j = 1; j < 5; j++)
			{
				if (equation[i + j] >= '0')
					cnt++;
				else
					break;
			}

			int value = 0;
			num[idx_num] = 0;

			for (int k = 0; k <= cnt; k++)
			{
				value = equation[i+k] - 48;

				for (int a = 0; a < cnt - k; a++)
					value *= 10;

				num[idx_num] += value;
			}

			i += cnt;
			idx_num++;
		}
	}

	// calculate
	int num_sub = 0;
	stack <int> stack_num;

	for (int i = idx_oper - 1; i >= 0; i--)
	{
		if (oper[i] == 0)
		{
			num[i] += num[i + 1];
		}
		else
		{
			num_sub += 1;
			stack_num.push(num[i+1]);
		}
	}
	
	int result = num[0];

	for (int i = 0; i < num_sub; i++)
	{
		result -= stack_num.top();
		stack_num.pop();
	}

	/* PRINT RESULT */
	cout << result;

	return 0;
}
