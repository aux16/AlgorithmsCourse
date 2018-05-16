#include <stdio.h>

void InsertSort(int A[], int N);

int main(void)
{
	int S[10] = { 10, 9, 8, 7, -6, 5, 4, 3, 2, 1 };
	InsertSort(S, 10);
	for(int i = 0; i < 10; i++)
		printf("%-3d", S[i]);
	getchar();
	return 0;
}

void InsertSort(int A[], int N)
{
	for(int i = 1; i < N; i++)
	{
		int temp = A[i], j = i - 1;
		for(; j >= 0; j--)
		{
			if(A[j] > temp)
				A[j+1] = A[j];
			else
				break;
		}
		A[j + 1] = temp;
	}
}