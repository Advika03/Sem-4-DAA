#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int mergecount=0;
int swapcount=0;

int merge(int arr[], int l,
           int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    mergecount=0;

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            mergecount+=m-i+1;
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
    return mergecount;
    
}

int mergeSort(int arr[],
               int l, int r)
{
    mergecount=0;
    if (l < r)
    {

        int m = l + (r - l) / 2;
        mergecount+=mergeSort(arr, l, m);
        mergecount+=mergeSort(arr, m + 1, r);
        mergecount+=merge(arr, l, m, r);        
        
    }
    return mergecount;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
 
    while (1) {
 
        do {
            i++;
        } while (arr[i] < pivot);
 
        do {
            j--;
        } while (arr[j] > pivot);
 
        if (i >= j)
            return j;
 
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        ++swapcount;
 
    }
}
 
int partition_r(int arr[], int low, int high)
{
    srand(time(0));
    int random = low + rand() % (high - low);
 
    int temp = arr[random];
    arr[random] = arr[low];
    arr[low] = temp;
    return partition(arr, low, high);
}

 
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition_r(arr, low, high);
 
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
        
    }
}
 
int main()
{
    FILE *fp;
    fp = fopen("Experiment2.txt", "w");
    int arr[100000];

    int arr_size = sizeof(arr) / sizeof(arr[0]);

    for (int k = 0; k < arr_size; k++)
    {
        arr[k] = rand() % 100 + 1;
    }

    fprintf(fp, "Unsorted array is \n");
    for (int i = 0; i < arr_size; i++)
        fprintf(fp, "%d ", arr[i]);
    printf("\n");

    printf("\nMerge Sort :  \n");
    fprintf(fp, "\nMerge Sort :  \n");

    for (int k = 100; k <= arr_size; k += 100)
    {
        clock_t start, end;
        double cpu_time_used;
        start = clock();

        mergeSort(arr, 0, k - 1);

        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        fprintf(fp, "\n\t %d elements \t time = %lf s. \t count = %d", k, cpu_time_used,mergecount);
        printf("\n %d elements time = %lf", k, cpu_time_used);
        printf("\n %d elements count = %d", k, mergecount);
        mergecount=0;
    }
    printf("\n");
    printf("\nQuick Sort :  \n");
    fprintf(fp, "\n");
    fprintf(fp, "\nQuick Sort :  \n");

    for (int k = 100; k <= arr_size; k += 100)
    {
        clock_t start, end;
        double cpu_time_used;
        start = clock();

        quickSort(arr, 0, k - 1);

        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        fprintf(fp, "\n\t %d elements \t time = %lf s. \t count = %d", k, cpu_time_used,swapcount);
        printf("\n %d elements %lf", k, cpu_time_used);
        printf("\n %d elements count = %d", k, swapcount);
        swapcount=0;
    }
    printf("\n");
    return 0;
}

