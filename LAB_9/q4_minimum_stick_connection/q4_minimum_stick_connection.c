/* Q4. Minimum cost to connect sticks using a min-heap.
   Complexity: O(n log n) time, O(n) space. */
#include <stdio.h>
#define MAX 10000
long long h[MAX + 5]; int size = 0;
void push(long long x) {
    int i = ++size;
    while (i > 1 && h[i/2] > x) { h[i] = h[i/2]; i /= 2; }
    h[i] = x;
}
long long pop(void) {
    long long out = h[1], x = h[size--]; int i=1,c;
    while ((c=i*2) <= size) {
        if (c+1 <= size && h[c+1] < h[c]) c++;
        if (x <= h[c]) break;
        h[i]=h[c]; i=c;
    }
    h[i]=x; return out;
}
int main(void) {
    int n, i; long long x, y, sum, total=0;
    printf("Enter number of sticks: ");
    if (scanf("%d",&n)!=1 || n<1 || n>MAX) return 1;
    for (i=0;i<n;i++) {
        printf("Length of stick %d: ",i+1);
        if (scanf("%lld",&x)!=1 || x<0) return 1;
        push(x);
    }
    while (size > 1) {
        x=pop(); y=pop(); sum=x+y; total+=sum; push(sum);
        printf("Connect %lld and %lld -> %lld (cost %lld)\n",x,y,sum,sum);
    }
    printf("Minimum total cost = %lld\n",total);
    printf("Complexity: O(n log n) time, O(n) space.\n");
    return 0;
}
