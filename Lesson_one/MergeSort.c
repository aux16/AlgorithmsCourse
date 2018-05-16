#include <stdio.h>
#include <stdlib.h>

void MergeSort(int A[], int Left, int Right);

int main(void)
{
	int S[10] = {10, -4, 8, 7, 11, 5, 4, 3, 2, 1};
	MergeSort(S, 0, 9);
	for(int i = 0; i < 10; i++)
		printf("%-3d", S[i]);
	getchar();
	return 0;
}

void MergeSort(int A[], int Left, int Right)
{
	if(Left == Right)
		return ;
	
	int Center = (Left+Right)/2;
	
	MergeSort(A, Left, Center);
	MergeSort(A, Center+1, Right);
	
	int n = Right - Left + 1;
	int * ar = (int *)malloc(n*sizeof(int));
	int L = Left, R = Center + 1;
	for(int i = 0; i < n; i ++)
	{
		if(L > Center)
		{
			ar[i] = A[R++];
			continue;
		}
		
		if(R > Right)
		{
			ar[i] = A[L++];
			continue;
		}
		
		if(A[L] < A[R])
			ar[i] = A[L++];
		else
			ar[i] = A[R++];
	}
	
	for(int i = 0; i < n; i++)
		A[Left+i] = ar[i];
}