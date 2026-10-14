/*
Q1. Fractional Knapsack with Deterioration Rate
Assumption used for this lab implementation:
- At current time t, item i has effective density (v[i]/w[i]) - lambda[i]*t.
- Select the remaining item with the highest positive current density.
- Take as much of it as capacity permits; time advances by the weight taken.
This is a dynamic greedy validation implementation for the stated model.
*/
#include <stdio.h>

#define MAX 100

int main(void) {
    int n, i, best;
    double W, used = 0.0, t = 0.0, total = 0.0;
    double v[MAX], w[MAX], decay[MAX], taken[MAX] = {0};

    printf("Enter number of items: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) return 1;
    printf("Enter capacity W: ");
    if (scanf("%lf", &W) != 1 || W < 0) return 1;

    for (i = 0; i < n; i++) {
        printf("Enter value, weight and decay rate for item %d: ", i + 1);
        if (scanf("%lf %lf %lf", &v[i], &w[i], &decay[i]) != 3 ||
            v[i] < 0 || w[i] <= 0 || decay[i] < 0) return 1;
    }

    while (used < W) {
        double bestDensity = 0.0;
        best = -1;
        for (i = 0; i < n; i++) {
            if (taken[i] + 1e-9 < w[i]) {
                double density = v[i] / w[i] - decay[i] * t;
                if (density > bestDensity) {
                    bestDensity = density;
                    best = i;
                }
            }
        }
        if (best == -1) break;

        {
            double amount = w[best] - taken[best];
            if (amount > W - used) amount = W - used;
            total += amount * bestDensity;
            taken[best] += amount;
            used += amount;
            t += amount;
        }
    }

    printf("\nSelected weight and fraction per item:\n");
    for (i = 0; i < n; i++)
        printf("Item %d: weight taken = %.3f, fraction = %.3f\n",
               i + 1, taken[i], taken[i] / w[i]);
    printf("Total weight used = %.3f\n", used);
    printf("Greedy estimated total value = %.3f\n", total);
    printf("Complexity: O(n^2) time, O(n) extra space.\n");
    return 0;
}
