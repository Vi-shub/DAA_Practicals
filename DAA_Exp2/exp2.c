#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print(int A[], int n)
{
    for(int i = 0; i<n; i++)
    {
        printf("%d ", A[i]);
    }
}

double numberGenertor(int n) 
{
    FILE *fp = fopen("num.txt", "w");
    clock_t start, end;
    double cpu_time_used;
    int p;
    start = clock();
    for(int i = 0; i < n; i++) 
    {
        p = (rand() + (rand()*133));
        fprintf(fp," %d\n", p);
        
    } 
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    fclose(fp);
    return cpu_time_used;
}



void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
    int j;
	for (j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);  
	return (i + 1);
}

void quicksort(int Arr[], int low, int high)
{
	if (low < high) {
		// pi = Partition index
		int pi = partition(Arr, low, high);
		quicksort(Arr, low, pi - 1);
		quicksort(Arr, pi + 1, high);           
	}
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    
    int L[n1], R[n2];
  
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
  
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}

int main()
{
    double createTime = numberGenertor(100000);
    printf("\n%lf\n", createTime);
    FILE * read, * fpsel, *fpins;
    fpsel = fopen("time.csv", "w");
    //fpins = fopen("./insertion.csv", "w");
    if(!fpsel)
        return 0;
    // if(!fpins)
    //     return 0;
    fprintf(fpsel, "Blocks,Mergesort,Quicksort\n");
    //fprintf(fpins, "Blocks, time\n");
    //int pass1, pass2;
    for(long int x = 1000; x<=100000; x+=1000)
    {
        read = fopen("num.txt", "r");
        int A[x], B[x];
        clock_t start1, end1, start2, end2;
        for(long int i = 0; i<x; i++)
        {
            fscanf(read, "%d\n", &A[i]);
            B[i] = A[i];
        }

        start1 = clock();
        mergeSort(A,0,x-1);
        end1 = clock();

        start2 = clock();
        quicksort(B,0,x-1);
        end2 = clock();

        double t1 = (double) (end1 - start1) / CLOCKS_PER_SEC;
        double t2 = (double) (end2 - start2) / CLOCKS_PER_SEC;
        printf("%6d | %lf | %lf\n", x, t1,t2);

        fprintf(fpsel, "%ld, %f, %f\n",x,t1,t2);
        //fprintf(fpins, "%ld, %f\n",x,t2);


        fclose(read);
    }
    fclose(fpsel);
    //fclose(fpins);
}