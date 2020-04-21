#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> og_list;

bool bin_search(int num, int start, int end)
{
	int mid = (start + end) / 2;
    
    if(start > end)
        return false;
    else
    {
	    if (num == og_list[mid])
		    return true;
	    else if (num < og_list[mid])
	    	return bin_search(num, start, mid - 1);
	    else if (num > og_list[mid])
		    return bin_search(num, mid + 1, end);
    }
}

/* BOJ 1920 */
int main() {
	int N, M;
	int temp;

	/* USER INPUT */
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		og_list.push_back(temp);
	}

	sort(og_list.begin(), og_list.end());

	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &temp);
        if(bin_search(temp, 0, N - 1))
		    printf("1\n");
        else
            printf("0\n");
	}

	/* Processing */


	/* PRINT RESULT */

	return 0;
}
