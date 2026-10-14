/* Q3. Minimum initial fuel / minimum refuelling stops.
   Input station distance from origin and fuel added there.
   Greedy max-heap selects the largest available fuel when needed.
   Complexity: O(n log n) time, O(n) space. */
#include <stdio.h>

#define MAX 10000

int heap[MAX + 5], hs = 0;
void push(int x) {
    int i = ++hs;
    while (i > 1 && heap[i / 2] < x) { heap[i] = heap[i / 2]; i /= 2; }
    heap[i] = x;
}
int pop(void) {
    int out = heap[1], x = heap[hs--], i = 1, c;
    while ((c = i * 2) <= hs) {
        if (c + 1 <= hs && heap[c + 1] > heap[c]) c++;
        if (x >= heap[c]) break;
        heap[i] = heap[c]; i = c;
    }
    heap[i] = x;
    return out;
}
void sortStations(int d[], int f[], int n) {
    int i, j, td, tf;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (d[j] > d[j + 1]) {
                td=d[j]; d[j]=d[j+1]; d[j+1]=td;
                tf=f[j]; f[j]=f[j+1]; f[j+1]=tf;
            }
}
int main(void) {
    int n, D, F, d[MAX], f[MAX], i, stops = 0, possible = 1;
    printf("Enter target distance D, starting fuel F, number of stations: ");
    if (scanf("%d %d %d", &D, &F, &n) != 3 || D < 0 || F < 0 || n < 0 || n > MAX) return 1;
    for (i=0; i<n; i++) {
        printf("Enter station distance and fuel: ");
        if (scanf("%d %d", &d[i], &f[i]) != 2 || d[i] < 0 || f[i] < 0 || d[i] > D) return 1;
    }
    sortStations(d, f, n);
    {
        long long reach = F;
        int idx = 0;
        while (reach < D) {
            while (idx < n && d[idx] <= reach) push(f[idx++]);
            if (hs == 0) { possible = 0; break; }
            reach += pop();
            stops++;
        }
    }
    if (possible) printf("Minimum refuelling stops = %d\n", stops);
    else printf("Target cannot be reached.\n");
    printf("Complexity: O(n^2) including simple station sort; heap phase O(n log n).\n");
    return 0;
}
