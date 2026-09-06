#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max(int a[], int n)
{
    int m = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > m) m = a[i];
    return m;
}

void largestTwo(int a[], int n)
{
    int l, s;

    if (a[0] > a[1])
        l = a[0], s = a[1];
    else
        l = a[1], s = a[0];

    for (int i = 2; i < n; i++)
    {
        if (a[i] > l)
            s = l, l = a[i];
        else if (a[i] > s)
            s = a[i];
    }

    printf("Largest = %d\nSecond Largest = %d\n", l, s);
}

double mean(int a[], int n)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return (double)sum / n;
}

int cmp(const void *x, const void *y)
{
    return *(int *)x - *(int *)y;
}

double median(int a[], int n)
{
    int *b = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        b[i] = a[i];

    qsort(b, n, sizeof(int), cmp);

    double m;
    if (n % 2)
        m = b[n / 2];
    else
        m = (b[n / 2 - 1] + b[n / 2]) / 2.0;

    free(b);
    return m;
}

double standardDeviation(int a[], int n)
{
    double m = mean(a, n);
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        double d = a[i] - m;
        sum += d * d;
    }

    return sqrt(sum / n);
}

int mode(int a[], int n)
{
    int ans = a[0], best = 1;

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
            if (a[i] == a[j])
                count++;

        if (count > best)
            best = count, ans = a[i];
    }

    return ans;
}

int removeDuplicates(int a[], int n)
{
    int size = 0;

    for (int i = 0; i < n; i++)
    {
        int duplicate = 0;

        for (int j = 0; j < size; j++)
            if (a[i] == a[j])
            {
                duplicate = 1;
                break;
            }

        if (!duplicate)
            a[size++] = a[i];
    }

    return size;
}

void reverseArray(int a[], int n)
{
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}

void partition(int a[], int n, int pivot)
{
    int i = 0, j = n - 1;

    while (i <= j)
    {
        while (i < n && a[i] >= pivot) i++;
        while (j >= 0 && a[j] < pivot) j--;

        if (i < j)
        {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int n, pivot;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));

    printf("Enter %d unsorted integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nOriginal Array: ");
    display(a, n);

    printf("\n(i) Maximum = %d\n", max(a, n));

    printf("\n(ii) First and Second Largest:\n");
    largestTwo(a, n);

    printf("\n(iii) Mean = %.2f\n", mean(a, n));

    printf("\n(iv) Median = %.2f\n", median(a, n));

    printf("\n(v) Standard Deviation = %.2f\n",
           standardDeviation(a, n));

    printf("\n(vi) Mode = %d\n", mode(a, n));

    n = removeDuplicates(a, n);
    printf("\n(vii) After Removing Duplicates: ");
    display(a, n);

    reverseArray(a, n);
    printf("\n(viii) Reversed Array: ");
    display(a, n);

    printf("\nEnter pivot: ");
    scanf("%d", &pivot);

    partition(a, n, pivot);
    printf("(ix) After Partitioning: ");
    display(a, n);

    free(a);
    return 0;
}