

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int c[], int n, FILE *fp)
{
     printf("\nINSERTION SORT: ");
	fprintf(fp,"\nINSERTION SORT: ");


	for (int k = 100; k <= n; k += 100)
	{
		clock_t start, end;
        double cpu_time_used;
	    start = clock();
		int a[n];
		for (int s = 0; s < n; s++)
		{
			a[s] = c[s];
		}

		for (int i = 1; i < k; i++)
		{
			int current = a[i];
			int j = i - 1;
			while (a[j] > current && j >= 0)
			{
				a[j + 1] = a[j];
				j--;
			}

			a[j + 1] = current;
		}

		end = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;


		printf("\n %lf", cpu_time_used);
		fprintf(fp,"\nTime taken to sort first %d numbers: %lf seconds.", k, cpu_time_used);
	}
}

void selectionSort(int c[],int n, FILE *fp)
{
    printf("\nSELECTION SORT: ");
	fprintf(fp,"\nSELECTION SORT: ");

	for (int k = 100; k <= n; k += 100)
	{
		clock_t start, end;
	    double cpu_time_used;
	    start = clock();
		int b[n];
		for (int s = 0; s < n; s++)
			{
				b[s] = c[s];
			}

		for (int i = 0; i < k - 1; i++)
		{

			int min = i;
			for (int j = i + 1; j < n; j++)
			{
				if (b[min] > b[j])
				{
					min = j;
				}
			}

			int temp = b[min];
			b[min] = b[i];
			b[i] = temp;
		}

		end = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;


		printf("\n%lf", cpu_time_used);
		fprintf(fp,"\nTime taken to sort first %d numbers: %lf seconds.", k, cpu_time_used);
	}
}

int main()
{

	FILE *fp;
    fp = fopen("Experiment 1b.txt","w");
    int n = 100000;
	int c[n];
	for (int k = 0; k < n; k++)
	{
		c[k] = rand() % 100 + 1;
	}

	fprintf(fp,"\nUnsorted Array: ");
	for (int k = 0; k < n; k++)
	{

		fprintf(fp," %d ", c[k]);
	}
	fprintf(fp,"\n");

	// insertion sort function
	//insertionSort(c,n,fp);

	printf("\n");
	fprintf(fp,"\n");

	//selection sort
	selectionSort(c,n,fp);

	return 0;
}

