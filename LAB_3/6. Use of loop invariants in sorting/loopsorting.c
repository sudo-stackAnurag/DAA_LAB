#include <stdio.h>

long long comparisons = 0;

void selectionSort(int A[], int n)
{
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for (j = i + 1; j < n; j++)
        {
            comparisons++;

            if (A[j] < A[minIndex])
                minIndex = j;
        }

        /* Exchange A[i] and A[minIndex] */
        temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    comparisons = 0;

    selectionSort(A, n);

    printf("\nSorted array:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\n\nNumber of comparisons = %lld\n", comparisons);

    printf("Theoretical comparisons = %lld\n",
           (long long)n * (n - 1) / 2);

    if (comparisons == (long long)n * (n - 1) / 2)
        printf("Result: Comparisons match the theoretical value.\n");

    printf("Time Complexity = Theta(n^2)\n");

    return 0;
}