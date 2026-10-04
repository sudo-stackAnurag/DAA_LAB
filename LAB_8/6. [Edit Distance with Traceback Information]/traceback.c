#include <stdio.h>
#include <string.h>

int min(int a, int b, int c)
{
    int m = a;

    if(b < m)
        m = b;

    if(c < m)
        m = c;

    return m;
}

int main()
{
    char A[100], B[100];

    printf("Enter first string: ");
    scanf("%s", A);

    printf("Enter second string: ");
    scanf("%s", B);

    int m = strlen(A);
    int n = strlen(B);

    int dp[m + 1][n + 1];

    // Base cases
    for(int i = 0; i <= m; i++)
        dp[i][0] = i;

    for(int j = 0; j <= n; j++)
        dp[0][j] = j;

    // Build DP table
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(
                    dp[i][j - 1] + 1,     // Insert
                    dp[i - 1][j] + 1,     // Delete
                    dp[i - 1][j - 1] + 1  // Substitute
                );
            }
        }
    }

    printf("\nMinimum Edit Distance = %d\n", dp[m][n]);

    // Traceback
    printf("\nTraceback:\n");

    int i = m;
    int j = n;

    while(i > 0 || j > 0)
    {
        // Characters are same
        if(i > 0 && j > 0 && A[i - 1] == B[j - 1])
        {
            printf("Keep '%c'\n", A[i - 1]);
            i--;
            j--;
        }

        // Substitution
        else if(i > 0 && j > 0 &&
                dp[i][j] == dp[i - 1][j - 1] + 1)
        {
            printf("Substitute '%c' -> '%c'\n",
                   A[i - 1], B[j - 1]);
            i--;
            j--;
        }

        // Deletion
        else if(i > 0 &&
                dp[i][j] == dp[i - 1][j] + 1)
        {
            printf("Delete '%c'\n", A[i - 1]);
            i--;
        }

        // Insertion
        else
        {
            printf("Insert '%c'\n", B[j - 1]);
            j--;
        }
    }

    return 0;
}