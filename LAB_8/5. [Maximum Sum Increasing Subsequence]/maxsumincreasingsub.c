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

    // Each element itself is an increasing subsequence
    for(int i = 0; i < n; i++)
        dp[i] = A[i];

    // Find maximum sum increasing subsequence
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(A[j] < A[i])
            {
                if(dp[j] + A[i] > dp[i])
                    dp[i] = dp[j] + A[i];
            }
        }
    }

    // Find maximum sum
    int ans = dp[0];

    for(int i = 1; i < n; i++)
    {
        if(dp[i] > ans)
            ans = dp[i];
    }

    printf("Maximum Sum = %d\n", ans);

    return 0;
}