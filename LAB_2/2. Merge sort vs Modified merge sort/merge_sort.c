#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 200000

/* ---------- Standard Merge Sort ---------- */

void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];

    for (int i = 0; i < n2; i++)
        R[i] = a[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1)
        a[k++] = L[i++];

    while (j < n2)
        a[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int a[], int l, int r)
{
    if (l >= r)
        return;

    int m = (l + r) / 2;

    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);

    merge(a, l, m, r);
}

/* ---------- 3-Way Merge Sort ---------- */

void merge3(int a[], int l, int m1, int m2, int r)
{
    int size = r - l + 1;

    int *temp = (int *)malloc(size * sizeof(int));

    int i = l;
    int j = m1 + 1;
    int k = m2 + 1;
    int t = 0;

    while (i <= m1 && j <= m2 && k <= r)
    {
        if (a[i] <= a[j] && a[i] <= a[k])
            temp[t++] = a[i++];
        else if (a[j] <= a[i] && a[j] <= a[k])
            temp[t++] = a[j++];
        else
            temp[t++] = a[k++];
    }

    while (i <= m1 && j <= m2)
        temp[t++] = (a[i] <= a[j]) ? a[i++] : a[j++];

    while (j <= m2 && k <= r)
        temp[t++] = (a[j] <= a[k]) ? a[j++] : a[k++];

    while (i <= m1 && k <= r)
        temp[t++] = (a[i] <= a[k]) ? a[i++] : a[k++];

    while (i <= m1)
        temp[t++] = a[i++];

    while (j <= m2)
        temp[t++] = a[j++];

    while (k <= r)
        temp[t++] = a[k++];

    for (int x = 0; x < size; x++)
        a[l + x] = temp[x];

    free(temp);
}

void mergeSort3(int a[], int l, int r)
{
    if (l >= r)
        return;

    int third = (r - l) / 3;

    int m1 = l + third;
    int m2 = l + 2 * third + 1;

    if (m2 > r)
        m2 = r;

    mergeSort3(a, l, m1);
    mergeSort3(a, m1 + 1, m2);
    mergeSort3(a, m2 + 1, r);

    merge3(a, l, m1, m2, r);
}

/* ---------- Main ---------- */

int main()
{
    FILE *fp = fopen("merge.dat", "w");

    if (fp == NULL)
    {
        printf("Error creating file.\n");
        return 1;
    }

    fprintf(fp, "#n MergeSort ThreeWayMergeSort\n");

    srand(time(NULL));

    int sizes[] = {1000, 5000, 10000, 20000, 50000, 100000};

    for (int s = 0; s < 6; s++)
    {
        int n = sizes[s];

        int *a = (int *)malloc(n * sizeof(int));
        int *b = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % 100000;
            b[i] = a[i];
        }

        clock_t start, end;

        start = clock();
        mergeSort(a, 0, n - 1);
        end = clock();

        double t1 = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        mergeSort3(b, 0, n - 1);
        end = clock();

        double t2 = (double)(end - start) / CLOCKS_PER_SEC;

        fprintf(fp, "%d %lf %lf\n", n, t1, t2);

        printf("%6d  %lf  %lf\n", n, t1, t2);

        free(a);
        free(b);
    }

    fclose(fp);

    printf("\nData stored in merge.dat\n");

    return 0;
}