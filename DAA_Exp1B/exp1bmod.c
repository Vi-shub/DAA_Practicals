#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print(int * A, int n)
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

int InsertionSort(int arr[], int n)
{
    int i, key, j;
    int totalpass = 0;
    for (i = 1; i < n; i++)
    {
        int pass = 0;
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            pass++;
        }
        arr[j + 1] = key;
        totalpass+=pass;
    }
    return totalpass;
}


int SelectionSort(int A[], int n)
{
    int totalpass =0;
    for(int i = 0; i<n-1; i++)
    {
        int min = A[i];
        int pos = i;
        int temp;
        int pass = 0;
        for(int j = i; j<n; j++)
        {
            if(A[j]<min)
            {
                min = A[j];
                pos = j;
                pass++;
            }
        }
        temp = A[i];
        A[i] = min;
        A[pos] = temp;
        totalpass+=pass;
    }
    return totalpass;
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
    fprintf(fpsel, "Blocks, Selection,Selection Passes,Insertion ,Insertion Passes\n");
    //fprintf(fpins, "Blocks, time\n");
    int pass1, pass2;
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
        pass1 = SelectionSort(A, x);
        end1 = clock();

        start2 = clock();
        pass2 = InsertionSort(B, x);
        end2 = clock();

        double t1 = (double) (end1 - start1) / CLOCKS_PER_SEC;
        double t2 = (double) (end2 - start2) / CLOCKS_PER_SEC;
        printf("%6d | %lf | %lf\n", x, t1, t2);

        fprintf(fpsel, "%ld, %f, %d, %f, %d\n",x,t1,pass1,t2,pass2);
        //fprintf(fpins, "%ld, %f\n",x,t2);


        fclose(read);
    }
    fclose(fpsel);
    //fclose(fpins);
}