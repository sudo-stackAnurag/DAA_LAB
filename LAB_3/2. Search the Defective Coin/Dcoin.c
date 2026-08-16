#include <stdio.h>

#define MAX 10000

int coin[MAX];
int weighings;

/* Simulates the balance scale */
int weigh(int left[], int n1, int right[], int n2)
{
    int leftWeight = 0;
    int rightWeight = 0;

    for (int i = 0; i < n1; i++)
        leftWeight += coin[left[i]];

    for (int i = 0; i < n2; i++)
        rightWeight += coin[right[i]];

    weighings++;

    if (leftWeight < rightWeight)
        return -1;

    if (leftWeight > rightWeight)
        return 1;

    return 0;
}

/* Divide-and-conquer defective coin search */
int findDefective(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    int leftSize = n / 2;
    int rightSize = n / 2;

    int left[MAX], right[MAX];

    for (int i = 0; i < leftSize; i++)
        left[i] = arr[i];

    for (int i = 0; i < rightSize; i++)
        right[i] = arr[leftSize + i];

    int extra = -1;

    if (n % 2 != 0)
        extra = arr[n - 1];

    int result = weigh(left, leftSize, right, rightSize);

    if (result == -1)
    {
        return findDefective(left, leftSize);
    }
    else if (result == 1)
    {
        return findDefective(right, rightSize);
    }
    else
    {
        if (extra != -1)
        {
            int normal = left[0];

            int a[1] = {extra};
            int b[1] = {normal};

            int check = weigh(a, 1, b, 1);

            if (check == -1)
                return extra;
        }

        return -1;
    }
}

int main()
{
    int n;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    if (n < 2 || n > MAX)
    {
        printf("Invalid number of coins.\n");
        return 1;
    }

    printf("\nEnter the weight of each coin:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Coin %d: ", i + 1);
        scanf("%d", &coin[i]);
    }

    int arr[MAX];

    for (int i = 0; i < n; i++)
        arr[i] = i;

    weighings = 0;

    int defective = findDefective(arr, n);

    printf("\n-----------------------------\n");

    if (defective == -1)
    {
        printf("No defective coin found.\n");
    }
    else
    {
        printf("Defective coin = Coin %d\n", defective + 1);
        printf("Weight = %d\n", coin[defective]);
    }

    printf("Number of weighings = %d\n", weighings);

    printf("-----------------------------\n");

    /*
       =====================================================
       GENERATE DATA FILE FOR GNUPLOT
       =====================================================
    */

    FILE *fp = fopen("data.dat", "w");

    if (fp == NULL)
    {
        printf("Error creating data.dat\n");
        return 1;
    }

    /*
       Test different numbers of coins.
       We use powers of 2 so that the divide-and-conquer
       behavior is easy to observe.
    */

    for (int testN = 2; testN <= 8192; testN *= 2)
    {
        /*
           Make every coin normal first.
        */
        for (int i = 0; i < testN; i++)
            coin[i] = 10;

        /*
           Put the defective coin at the end.
           This produces a long search path.
        */
        coin[testN - 1] = 9;

        int testArr[MAX];

        for (int i = 0; i < testN; i++)
            testArr[i] = i;

        weighings = 0;

        findDefective(testArr, testN);

        /*
           Format:
           n    number_of_weighings
        */
        fprintf(fp, "%d %d\n", testN, weighings);
    }

    fclose(fp);

    printf("\ndata.dat created successfully.\n");

    return 0;
}