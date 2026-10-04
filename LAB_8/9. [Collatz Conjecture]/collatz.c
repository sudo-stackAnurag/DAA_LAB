#include <stdio.h>
#include <stdlib.h>

void collatz(long long n)
{
    printf("%lld", n);

    while(n != 1)
    {
        if(n % 2 == 0)
            n = n / 2;
        else
            n = 3 * n + 1;

        printf(" -> %lld", n);
    }

    printf("\n");
}

int main()
{
    long long n, a, b;

    printf("Enter starting value n: ");
    scanf("%lld", &n);

    if(n <= 0)
    {
        printf("Enter a positive integer.\n");
        return 1;
    }

    printf("\nCollatz sequence for %lld:\n", n);
    collatz(n);

    printf("\nEnter interval [a b]: ");
    scanf("%lld %lld", &a, &b);

    if(a <= 0 || b < a)
    {
        printf("Invalid interval.\n");
        return 1;
    }

    printf("\nCollatz trajectories:\n");

    for(long long i = a; i <= b; i++)
    {
        printf("%lld: ", i);
        collatz(i);
    }

    return 0;
}