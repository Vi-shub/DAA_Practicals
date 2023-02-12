#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <iostream>
#include <random>
using namespace std;

//gcc test.cpp -lstdc++

double numberGenertor(int a[], int b[], int n) 
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    
    random_device rd; //random number function 
    for (int i = 0; i < 100000; i++)  // generator random number between 1 to 100000 consisting of 1000 block each
    {
        uniform_int_distribution<int> dist(1,10000000000);
        a[i] = b[i] = dist(rd);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    FILE *fp = fopen("./selection.txt", "w+");
    for(int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", a[i]);
    }
    fclose(fp);
    fp = fopen("./insertion.txt", "w+");
    for(int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", b[i]);
    }
    fclose(fp);
    return cpu_time_used;
}

double selectionSort(int a[], int n) 
{
    FILE *fp = fopen("./selection.csv", "w+");
    double totalTime = 0;
    if(!fp) {
        printf("Error in opening file\n");
        return -1;
    }
    fprintf(fp, "n, time\n");
    for (int y = 100; y <= n; y+=100)
    {
        clock_t start, end;
        double iterationTime;
        start = clock();
        for (int i = 0; i < y-1; i++)
        {
            int k = i;
            for (int j = i+1; j < y; j++)
            {
                if (a[j]<a[k])
                {
                    k = j;   
                }
            }
            int temp = a[k];
            a[k] = a[i];
            a[i] = temp;
        }
        end = clock();
        iterationTime = ((double) (end - start)) / CLOCKS_PER_SEC;
        totalTime += iterationTime;
        fprintf(fp, "%d, %f\n", y, iterationTime);
        
        printf("Array[0...%d99] sorted in %.4fs\n", (y/100), iterationTime);
    }
    fclose(fp);
    return totalTime;
}


double insertionSort(int a[], int n) 
{
    FILE *fp = fopen("./insertion.csv", "w+");
    
    double totalTime = 0;
    if(!fp) {
        printf("Error in opening file\n");
        return -1;
    }
    fprintf(fp, "n, time\n");
    for (int y = 100; y <= n; y+=100)
    {
        clock_t start, end;
        double iterationTime;
        start = clock();
        int j, x;
        for (int i = 1; i < y; i++)
        {
            j = i-1;
            x = a[i];
            while (j>-1 && a[j]>x)
            {
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = x;
        }
        end = clock();
        iterationTime = ((double) (end - start)) / CLOCKS_PER_SEC;
        totalTime += iterationTime;
        fprintf(fp, "%d, %f\n", y, iterationTime);
        
        printf("Array[0...%d99] sorted in %.4fs\n", (y/100), iterationTime);

    }
    fclose(fp);
    return totalTime;
}

int main()
{
    int n = 100000;
    int a[n],b[n];
    printf("Clock per second of the computer : %d\n",CLOCKS_PER_SEC);
    double timeToFill = numberGenertor(a, b, n);
    printf("Time to generate random number : %f\n", timeToFill);
    printf("Insertion sort\n");
    //insertion sort from 0 to 100000
    double insertionTime = insertionSort(a, n);
    printf("Selection sort\n");
    //selection sort from 0 to 100000
    double selectionTime = selectionSort(b, n);
    printf("Time taken by insertion sort :  %.4f\n", insertionTime);
    printf("Time taken by selection sort :  %.4f\n", selectionTime);
    printf("Total time taken by program : %f\n", insertionTime + selectionTime);
    
    return 0;
}