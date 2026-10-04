#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n], dp[n];

    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    // Every element itself forms an increasing subsequence
    for(int i = 0; i < n; i++)
        dp[i] = 1;

    // Find LIS ending at every element
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(A[j] < A[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
    }

    // Find maximum LIS length
    int ans = dp[0];

    for(int i = 1; i < n; i++)
    {
        if(dp[i] > ans)
            ans = dp[i];
    }

    printf("Length of LIS = %d\n", ans);

    return 0;
}