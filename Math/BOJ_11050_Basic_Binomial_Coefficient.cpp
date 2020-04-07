#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

using namespace std;

int cnt = 0;

int factorial(int num)
{
	int result=1;
	for (int i = 2; i <= num; i++)
	{
		result *= i;
	}

	return result;
}

/* BOJ 11050 */
int main() {
	int N, K;

	/* USER INPUT */
	scanf("%d", &N);
	scanf("%d", &K);

	/* Processing */
	cnt = factorial(N) / (factorial(K) * factorial(N - K));

	/* PRINT RESULT */
	printf("%d", cnt);

	return 0;
}
