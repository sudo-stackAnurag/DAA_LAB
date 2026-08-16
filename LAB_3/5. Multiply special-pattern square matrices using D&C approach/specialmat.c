#include <stdio.h>
#include <stdlib.h>

#define MAX 128

long long multiplications = 0;

/* Allocate matrix */
int **allocateMatrix(int n)
{
    int **A = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
        A[i] = (int *)calloc(n, sizeof(int));

    return A;
}

/* Free matrix */
void freeMatrix(int **A, int n)
{
    for (int i = 0; i < n; i++)
        free(A[i]);

    free(A);
}

/* Add matrices */
void addMatrix(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

/* Subtract matrices */
void subtractMatrix(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

/*
    Special-pattern matrix multiplication.

    A = [ A1 A2 ]
        [ A2 A1 ]

    B = [ B1 B2 ]
        [ B2 B1 ]
*/
void specialMultiply(int **A, int **B, int **C, int n)
{
    /* Base case */
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        multiplications++;
        return;
    }

    int k = n / 2;

    /*
        Allocate the four blocks:
        
        A = [A1 A2]
            [A2 A1]

        B = [B1 B2]
            [B2 B1]
    */

    int **A1 = allocateMatrix(k);
    int **A2 = allocateMatrix(k);

    int **B1 = allocateMatrix(k);
    int **B2 = allocateMatrix(k);

    /* Temporary matrices */
    int **Aplus = allocateMatrix(k);
    int **Aminus = allocateMatrix(k);

    int **Bplus = allocateMatrix(k);
    int **Bminus = allocateMatrix(k);

    int **P = allocateMatrix(k);
    int **Q = allocateMatrix(k);

    /*
        Extract A1, A2, B1, B2
    */
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A1[i][j] = A[i][j];
            A2[i][j] = A[i][j + k];

            B1[i][j] = B[i][j];
            B2[i][j] = B[i][j + k];
        }
    }

    /*
        P = (A1 + A2)(B1 + B2)
    */
    addMatrix(A1, A2, Aplus, k);
    addMatrix(B1, B2, Bplus, k);

    specialMultiply(Aplus, Bplus, P, k);

    /*
        Q = (A1 - A2)(B1 - B2)
    */
    subtractMatrix(A1, A2, Aminus, k);
    subtractMatrix(B1, B2, Bminus, k);

    specialMultiply(Aminus, Bminus, Q, k);

    /*
        C1 = (P + Q) / 2
        C2 = (P - Q) / 2
    */

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int C1 = (P[i][j] + Q[i][j]) / 2;
            int C2 = (P[i][j] - Q[i][j]) / 2;

            /*
                C = [C1 C2]
                    [C2 C1]
            */

            C[i][j] = C1;
            C[i][j + k] = C2;
            C[i + k][j] = C2;
            C[i + k][j + k] = C1;
        }
    }

    /* Free memory */
    freeMatrix(A1, k);
    freeMatrix(A2, k);

    freeMatrix(B1, k);
    freeMatrix(B2, k);

    freeMatrix(Aplus, k);
    freeMatrix(Aminus, k);

    freeMatrix(Bplus, k);
    freeMatrix(Bminus, k);

    freeMatrix(P, k);
    freeMatrix(Q, k);
}

/* Check if n is a power of 2 */
int isPowerOfTwo(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

int main()
{
    int n;

    printf("Enter size of matrices (n = 2^k): ");
    scanf("%d", &n);

    if (!isPowerOfTwo(n) || n > MAX)
    {
        printf("Invalid size. n must be a power of 2.\n");
        return 1;
    }

    int **A = allocateMatrix(n);
    int **B = allocateMatrix(n);
    int **C = allocateMatrix(n);

    printf("\nEnter Matrix A:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    }

    printf("\nEnter Matrix B:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);
    }

    multiplications = 0;

    specialMultiply(A, B, C, n);

    printf("\nResult Matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }

    printf("\nNumber of scalar multiplications = %lld\n",
           multiplications);

    printf("\nTime Complexity = O(n^2)\n");

    /*
        Generate data for GNUplot
    */
    FILE *fp = fopen("data.dat", "w");

    if (fp == NULL)
    {
        printf("Error creating data.dat\n");
    }
    else
    {
        /*
            Generate theoretical values:
            n^2
        */

        for (int size = 2; size <= 128; size *= 2)
        {
            printf("n = %d -> theoretical work = %d\n",
                   size, size * size);

            fprintf(fp, "%d %d\n",
                    size, size * size);
        }

        fclose(fp);

        printf("\ndata.dat created successfully.\n");
    }

    freeMatrix(A, n);
    freeMatrix(B, n);
    freeMatrix(C, n);

    return 0;
}