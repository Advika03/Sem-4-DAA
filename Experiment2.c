#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l,
           int m, int r)
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
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
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

void mergeSort(int arr[],
               int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
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

        fprintf(fp, "\nTime taken for %d elements %lf seconds.", k, cpu_time_used);
        printf("\n %d elements %lf ", k, cpu_time_used);
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

        quicksort(arr, 0, k - 1);

        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        fprintf(fp, "\nTime taken for %d elements %lf seconds", k, cpu_time_used);
        printf("\n %d elements %lf", k, cpu_time_used);
    }
    printf("\n");
    return 0;
}

void quicksort(int number[25], int first, int last)
{
    int i, j, pivot, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (number[i] <= number[pivot] && i < last)
                i++;
            while (number[j] > number[pivot])
                j--;
            if (i < j)
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort(number, first, j - 1);
        quicksort(number, j + 1, last);
    }
}