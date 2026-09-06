#include <stdio.h>
#include <math.h>

#define MAX 20
#define EPS 0.000001
#define ITER 1000

void display(int A[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
}

void add(int A[MAX][MAX], int B[MAX][MAX],
         int C[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void multiply(int A[MAX][MAX], int B[MAX][MAX],
              int C[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int zeroMatrix(int A[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] != 0)
                return 0;
    return 1;
}

int symmetric(int A[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (A[i][j] != A[j][i])
                return 0;
    return 1;
}

double determinant(int A[MAX][MAX], int n)
{
    double B[MAX][MAX], det = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            B[i][j] = A[i][j];

    for (int i = 0; i < n; i++)
    {
        int p = i;

        for (int j = i + 1; j < n; j++)
            if (fabs(B[j][i]) > fabs(B[p][i]))
                p = j;

        if (fabs(B[p][i]) < EPS)
            return 0;

        if (p != i)
        {
            for (int j = 0; j < n; j++)
            {
                double t = B[i][j];
                B[i][j] = B[p][j];
                B[p][j] = t;
            }
            det = -det;
        }

        det *= B[i][i];

        for (int j = i + 1; j < n; j++)
        {
            double f = B[j][i] / B[i][i];

            for (int k = i + 1; k < n; k++)
                B[j][k] -= f * B[i][k];
        }
    }

    return det;
}

void transpose(int A[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int t = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = t;
        }
}

/* Finds dominant eigenvalue and eigenvector */
void eigen(int A[MAX][MAX], int n)
{
    double x[MAX], y[MAX], value = 0;

    for (int i = 0; i < n; i++)
        x[i] = 1;

    for (int it = 0; it < ITER; it++)
    {
        for (int i = 0; i < n; i++)
        {
            y[i] = 0;
            for (int j = 0; j < n; j++)
                y[i] += A[i][j] * x[j];
        }

        double mx = fabs(y[0]);

        for (int i = 1; i < n; i++)
            if (fabs(y[i]) > mx)
                mx = fabs(y[i]);

        double error = 0;

        for (int i = 0; i < n; i++)
        {
            y[i] /= mx;
            error += fabs(y[i] - x[i]);
            x[i] = y[i];
        }

        value = mx;

        if (error < EPS)
            break;
    }

    printf("Dominant Eigenvalue = %.4f\n", value);
    printf("Eigenvector:\n");

    for (int i = 0; i < n; i++)
        printf("%.4f\n", x[i]);
}

int main()
{
    int n, A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    printf("Enter order of square matrices: ");
    scanf("%d", &n);

    printf("\nEnter Matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("\nEnter Matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    add(A, B, C, n);
    printf("\n(i) Matrix Addition:\n");
    display(C, n);

    multiply(A, B, C, n);
    printf("\n(ii) Matrix Multiplication:\n");
    display(C, n);

    printf("\n(iii) Zero Matrix A: %s\n",
           zeroMatrix(A, n) ? "Yes" : "No");

    printf("\n(iv) Symmetric Matrix A: %s\n",
           symmetric(A, n) ? "Yes" : "No");

    printf("Symmetric Matrix B: %s\n",
           symmetric(B, n) ? "Yes" : "No");

    printf("\n(v) Determinant of A = %.2f\n",
           determinant(A, n));

    transpose(A, n);
    printf("\n(vi) Transpose of A:\n");
    display(A, n);

    printf("\n(vii) Eigenvalue and Eigenvector of B:\n");
    eigen(B, n);

    return 0;
}