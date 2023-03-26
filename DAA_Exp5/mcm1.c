#include <stdio.h>
#include <limits.h>
#include <stdio.h>
int m[10][10];
int MatrixChainOrder(int p[], int n)
{
	
    //int m[n][n];
	int i, j, k, L, q;
	// cost is zero when multiplying one matrix.
	for (i = 1; i < n; i++)
		m[i][i] = 0;

	// L is chain length.
	for (L = 2; L < n; L++) {
		for (i = 1; i < n - L + 1; i++) {
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++) {
				// q = cost/scalar multiplications
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
					m[i][j] = q;
			}
		}
	}
    printf("\n");
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (i<=j)
            {
			   printf("\t\t%d",m[i][j]);
            }
            else
				printf("\t\t0");  
        }
        printf("\n");
    }
	return m[1][n - 1];
}

int main()
{
	int arr[] = { 2 ,4 ,6 ,8 ,6 };
	int size = sizeof(arr) / sizeof(arr[0]);
    printf("\nUsing dynamic programming approach");
	printf("\nMinimum number of multiplications is %d\n ",MatrixChainOrder(arr, size));
    return 0;
}
