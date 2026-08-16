#include <stdio.h>

int comparisons = 0;

struct MinMax
{
    int min;
    int max;
};

struct MinMax findMinMax(int arr[], int low, int high)
{
    struct MinMax result;
    struct MinMax leftResult;
    struct MinMax rightResult;

    /*
        Case 1: Only one element
    */
    if (low == high)
    {
        result.min = arr[low];
        result.max = arr[low];

        return result;
    }

    /*
        Case 2: Two elements
    */
    if (high == low + 1)
    {
        comparisons++;

        if (arr[low] < arr[high])
        {
            result.min = arr[low];
            result.max = arr[high];
        }
        else
        {
            result.min = arr[high];
            result.max = arr[low];
        }

        return result;
    }

    /*
        Case 3: More than two elements
        Divide the array into two halves.
    */
    int mid = low + (high - low) / 2;

    leftResult = findMinMax(arr, low, mid);
    rightResult = findMinMax(arr, mid + 1, high);

    /*
        Compare the minimum values
    */
    comparisons++;

    if (leftResult.min < rightResult.min)
        result.min = leftResult.min;
    else
        result.min = rightResult.min;

    /*
        Compare the maximum values
    */
    comparisons++;

    if (leftResult.max > rightResult.max)
        result.max = leftResult.max;
    else
        result.max = rightResult.max;

    return result;
}

int main()
{
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    comparisons = 0;

    struct MinMax result = findMinMax(arr, 0, n - 1);

    printf("\n-----------------------------\n");
    printf("Minimum element = %d\n", result.min);
    printf("Maximum element = %d\n", result.max);
    printf("Number of comparisons = %d\n", comparisons);

    /*
        The theoretical upper bound is approximately 3n/2.
    */
    printf("3n/2 = %.1f\n", (3.0 * n) / 2);

    if (comparisons <= (3 * n) / 2)
        printf("Comparison bound satisfied.\n");
    else
        printf("Comparison bound exceeded.\n");

    printf("-----------------------------\n");

    return 0;
}