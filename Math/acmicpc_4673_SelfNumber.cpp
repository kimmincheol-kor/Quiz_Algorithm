#include <iostream>

int d(int n);

int self_num[10000] = { 0, };

int main() {
	int temp;

	for (int a = 1; a <= 10000; a++)
	{
		if (self_num[a - 1]) continue;
		
		int I = a;

		while (1)
		{
			I = d(I);

			if (I > 10000)
				break;
			else
				self_num[I-1] = 1;
		}
	}

	for (int a = 0; a < 10000; a++)
	{
		if (!self_num[a])
		{
			std::cout << a + 1 << ' ';
		}
	}

	return 0;
}

int d(int n)
{
	int sum = n;

	while (1)
	{
		sum += n % 10;
		n /= 10;

		if (n == 0)
			break;
	}

	return sum;
}