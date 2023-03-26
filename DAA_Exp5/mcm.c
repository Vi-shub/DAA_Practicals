#include <stdio.h>
#include <limits.h>
#include <stdio.h>


int MatrixChainOrder(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int min = INT_MAX;
	int count;

	for (k = i; k < j; k++) {
		count = MatrixChainOrder(p, i, k) +
				MatrixChainOrder(p, k + 1, j) +
				p[i - 1] * p[k] * p[j];

		if (count < min)
			min = count;
	}

	return min;
}

int main()
{
	int arr[] = { 2, 4, 6, 8, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
    printf("\nUsing recursion and optimal subtree solution");
	printf("\nMinimum number of multiplications is %d\n ",MatrixChainOrder(arr, 1, n - 1));
	return 0;
}
