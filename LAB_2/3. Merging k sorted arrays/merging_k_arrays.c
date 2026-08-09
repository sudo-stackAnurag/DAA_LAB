#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TESTS 6
#define N 10000

/* Merge two sorted arrays */
int *merge(int *a, int na, int *b, int nb)
{
    int *c = malloc((na + nb) * sizeof(int));
    int i = 0, j = 0, k = 0;

    while (i < na && j < nb)
        c[k++] = (a[i] <= b[j]) ? a[i++] : b[j++];

    while (i < na)
        c[k++] = a[i++];

    while (j < nb)
        c[k++] = b[j++];

    return c;
}

/* Generate a sorted array of n random values */
int *generate_array(int n)
{
    int *a = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000000;

    /* Simple insertion sort */
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }

    return a;
}

/* Method 1:
   Merge first two, then result with third, etc. */
int *method1(int **a, int k, int n)
{
    int *result = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        result[i] = a[0][i];

    int size = n;

    for (int i = 1; i < k; i++)
    {
        int *temp = merge(result, size, a[i], n);

        free(result);
        result = temp;
        size += n;
    }

    return result;
}

/* Method 2:
   Merge arrays in pairs repeatedly. */
int *method2(int **a, int k, int n)
{
    int count = k;

    int **current = malloc(k * sizeof(int *));
    int *sizes = malloc(k * sizeof(int));

    for (int i = 0; i < k; i++)
    {
        current[i] = malloc(n * sizeof(int));

        for (int j = 0; j < n; j++)
            current[i][j] = a[i][j];

        sizes[i] = n;
    }

    while (count > 1)
    {
        int newCount = 0;

        for (int i = 0; i < count; i += 2)
        {
            if (i + 1 < count)
            {
                int *merged = merge(
                    current[i], sizes[i],
                    current[i + 1], sizes[i + 1]
                );

                free(current[i]);
                free(current[i + 1]);

                current[newCount] = merged;
                sizes[newCount] = sizes[i] + sizes[i + 1];

                newCount++;
            }
            else
            {
                current[newCount] = current[i];
                sizes[newCount] = sizes[i];
                newCount++;
            }
        }

        count = newCount;
    }

    int *result = current[0];

    free(current);
    free(sizes);

    return result;
}

int main()
{
    int k_values[NUM_TESTS] = {2, 4, 8, 16, 32, 64};

    FILE *fp = fopen("merging_k.dat", "w");

    if (fp == NULL)
    {
        printf("Error creating data file.\n");
        return 1;
    }

    fprintf(fp, "# k Method1 Method2\n");

    srand((unsigned)time(NULL) ^ clock());

    for (int t = 0; t < NUM_TESTS; t++)
    {
        int k = k_values[t];

        printf("Testing k = %d...\n", k);

        /* Generate the same input for both methods */
        int **arrays = malloc(k * sizeof(int *));

        for (int i = 0; i < k; i++)
            arrays[i] = generate_array(N);

        /* Method 1 */
        clock_t start = clock();

        int *result1 = method1(arrays, k, N);

        clock_t end = clock();

        double time1 =
            (double)(end - start) / CLOCKS_PER_SEC;

        free(result1);

        /* Method 2 */
        start = clock();

        int *result2 = method2(arrays, k, N);

        end = clock();

        double time2 =
            (double)(end - start) / CLOCKS_PER_SEC;

        free(result2);

        fprintf(fp, "%d %.8f %.8f\n", k, time1, time2);

        printf("Method 1: %.8f s\n", time1);
        printf("Method 2: %.8f s\n\n", time2);

        for (int i = 0; i < k; i++)
            free(arrays[i]);

        free(arrays);
    }

    fclose(fp);

    printf("Data saved to merging_k.dat\n");

    return 0;
}