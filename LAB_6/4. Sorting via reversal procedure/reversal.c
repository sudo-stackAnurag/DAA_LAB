#include <stdio.h>
#include <stdlib.h>

long long revCount = 0;
long long totalCost = 0;

/* Reverse p[i...j] */
void reverse(int p[], int i, int j)
{
    if (i >= j)
        return;

    revCount++;
    totalCost += j - i + 1;

    while (i < j)
    {
        int t = p[i];
        p[i] = p[j];
        p[j] = t;
        i++;
        j--;
    }
}

/*
   Stable partition:
   <= pivot | > pivot
*/
int partition(int p[], int l, int r, int pivot)
{
    if (l == r)
        return p[l] <= pivot;

    int mid = (l + r) / 2;

    int leftLow = partition(p, l, mid, pivot);
    int rightLow = partition(p, mid + 1, r, pivot);

    /*
       Before rotation:
       L1 H1 L2 H2

       After rotation:
       L1 L2 H1 H2
    */

    int h1l = l + leftLow;
    int h1r = mid;
    int l2l = mid + 1;
    int l2r = mid + rightLow;

    if (h1l <= h1r && l2l <= l2r)
    {
        reverse(p, h1l, h1r);
        reverse(p, l2l, l2r);
        reverse(p, h1l, l2r);
    }

    return leftLow + rightLow;
}

void sortByReversal(int p[], int l, int r,
                    int low, int high)
{
    if (l >= r || low >= high)
        return;

    int pivot = (low + high) / 2;

    int count = partition(p, l, r, pivot);
    int split = l + count;

    sortByReversal(p, l, split - 1,
                   low, pivot);

    sortByReversal(p, split, r,
                   pivot + 1, high);
}

void display(int p[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", p[i]);

    printf("\n");
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *p = malloc(n * sizeof(int));

    printf("Enter permutation of 1 to %d:\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("\nOriginal permutation:\n");
    display(p, n);

    sortByReversal(p, 0, n - 1, 1, n);

    printf("\nSorted permutation:\n");
    display(p, n);

    printf("\nNumber of reversals = %lld\n",
           revCount);

    printf("Total reversal cost = %lld\n",
           totalCost);

    free(p);

    return 0;
}