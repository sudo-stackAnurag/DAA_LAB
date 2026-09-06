#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct
{
    double r, i;
} Complex;

Complex add(Complex a, Complex b)
{
    Complex c = {a.r + b.r, a.i + b.i};
    return c;
}

Complex sub(Complex a, Complex b)
{
    Complex c = {a.r - b.r, a.i - b.i};
    return c;
}

Complex mul(Complex a, Complex b)
{
    Complex c;

    c.r = a.r * b.r - a.i * b.i;
    c.i = a.r * b.i + a.i * b.r;

    return c;
}

void FFT(Complex a[], int n, int inv)
{
    if (n == 1)
        return;

    Complex even[n / 2], odd[n / 2];

    for (int i = 0; i < n / 2; i++)
    {
        even[i] = a[2 * i];
        odd[i] = a[2 * i + 1];
    }

    FFT(even, n / 2, inv);
    FFT(odd, n / 2, inv);

    double angle = 2 * PI / n;

    if (!inv)
        angle = -angle;

    Complex w = {1, 0};
    Complex wn = {cos(angle), sin(angle)};

    for (int k = 0; k < n / 2; k++)
    {
        Complex t = mul(w, odd[k]);

        a[k] = add(even[k], t);
        a[k + n / 2] = sub(even[k], t);

        w = mul(w, wn);
    }

    if (inv)
        for (int i = 0; i < n; i++)
        {
            a[i].r /= n;
            a[i].i /= n;
        }
}

int nextPower(int n)
{
    int p = 1;

    while (p < n)
        p *= 2;

    return p;
}

int main()
{
    int m, n;

    printf("Enter size of vector A: ");
    scanf("%d", &m);

    printf("Enter size of vector B: ");
    scanf("%d", &n);

    if (m > n)
    {
        printf("Condition n >= m is required.\n");
        return 0;
    }

    int size = m + n - 1;
    int N = nextPower(size);

    Complex *A = calloc(N, sizeof(Complex));
    Complex *B = calloc(N, sizeof(Complex));

    printf("\nEnter elements of A:\n");
    for (int i = 0; i < m; i++)
        scanf("%lf", &A[i].r);

    printf("\nEnter elements of B:\n");
    for (int i = 0; i < n; i++)
        scanf("%lf", &B[i].r);

    FFT(A, N, 0);
    FFT(B, N, 0);

    for (int i = 0; i < N; i++)
        A[i] = mul(A[i], B[i]);

    FFT(A, N, 1);

    printf("\nConvolution:\n");

    for (int i = 0; i < size; i++)
        printf("%.0f ", A[i].r);

    printf("\n");

    free(A);
    free(B);

    return 0;
}