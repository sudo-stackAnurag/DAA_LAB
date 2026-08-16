#include <stdio.h>
#include <math.h>

int binaryComparisons = 0;
int ternaryComparisons = 0;

// Binary Search Function
int binarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        binaryComparisons++;

        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// Ternary Search Function
int ternarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        ternaryComparisons++;

        if (arr[mid1] == key)
            return mid1;

        ternaryComparisons++;

        if (arr[mid2] == key)
            return mid2;

        if (key < arr[mid1])
            high = mid1 - 1;
        else if (key > arr[mid2])
            low = mid2 + 1;
        else
        {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }
    return -1;
}

int main()
{
    int n, x;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search: ");
    scanf("%d", &x);

    int bIndex = binarySearch(arr, 0, n - 1, x);
    int tIndex = ternarySearch(arr, 0, n - 1, x);

    printf("\n----- Binary Search -----\n");
    if (bIndex != -1)
        printf("Element found at index %d\n", bIndex);
    else
        printf("Element not found\n");
    printf("Comparisons = %d\n", binaryComparisons);

    printf("\n----- Ternary Search -----\n");
    if (tIndex != -1)
        printf("Element found at index %d\n", tIndex);
    else
        printf("Element not found\n");
    printf("Comparisons = %d\n", ternaryComparisons);

    printf("\n----- Conclusion -----\n");
    if (binaryComparisons < ternaryComparisons)
        printf("Binary Search performed better with fewer comparisons.\n");
    else if (binaryComparisons > ternaryComparisons)
        printf("Ternary Search performed better.\n");
    else
        printf("Both searches performed the same.\n");
    FILE *fp = fopen("search_data.dat", "w");

    if (fp == NULL)
    {
        printf("Error creating file.\n");
        return 1;
    }

    for (int n = 10; n <= 1000000; n *= 2)
    {
        double binary = log2(n);
        double ternary = log(n) / log(3);

        fprintf(fp, "%d %.2f %.2f\n", n, binary, ternary);
    }

    fclose(fp);

    printf("search_data.dat created successfully.\n");
    return 0;
}