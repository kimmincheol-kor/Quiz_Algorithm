#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNING

int queen_turn(int* board, int num);
void print_board(int* board);
int check_queen(int* board, int num);

int N;

int main()
{
	int * board;

	do {
		scanf_s("%d", &N);
	} while (N != 8 && N != 26 && N != 213 && N != 2012 && N != 99991 && N != 99999);

	board = (int*) malloc(N * sizeof(int));

	for (int i = 0; i < N; i++)
	{
		board[i] = 0;
	}

	queen_turn(board, 0);

	print_board(board);

	free(board);
}

int queen_turn(int* board, int num)
{
	for (int i = 0; i < N; i++)
	{
		board[num]++;

		if (check_queen(board, num) == 1) // no problem
		{
			if (num == N - 1) // end of game
				return 1;

			if (queen_turn(board, num + 1) == 1)
				return 1;
		}
	}

	board[num] = 0;

	return -1;
}

void print_board(int * board)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", board[i]);
	}
}

int check_queen(int* board, int num)
{
	int temp;
	temp = board[num];

	// 세로 확인
	for (int i = 0; i < num; i++)
	{
		if (board[i] == temp)
			return -1;
	}

	// 아래 오른쪽 대각선
	for (int i = 1; num + i < N && temp + i <= N ; i++)
	{
		if (board[num + i] == temp + i)
			return -1;
	}

	// 아래 왼쪽 대각선
	for (int i = 1; num + i < N && temp - i >= 1; i++)
	{
		if (board[num + i] == temp - i)
			return -1;
	}

	// 위 오른쪽 대각선
	for (int i = 1; num - i >= 0 && temp + i <= N; i++)
	{
		if (board[num - i] == temp + i)
			return -1;
	}

	// 위 왼쪽 대각선
	for (int i = 1; num - i >= 0 && temp - i >= 1; i++)
	{
		if (board[num - i] == temp - i)
			return -1;
	}

	return 1;
}
