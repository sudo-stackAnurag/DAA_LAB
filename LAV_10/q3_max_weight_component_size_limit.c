/* Q3: Maximum vertex-weight sum among components of size <= K.
   Input: V E K, V vertex weights, then E edges u v edgeWeight (0-based vertices).
   Edge weights are read as requested but do not affect connectivity or the stated score.
   A max-heap with lazy invalidation keeps eligible component sums. */
#include <stdio.h>
#include <stdlib.h>

typedef struct { long long sum; int root, version; } Entry;
typedef struct { Entry *a; int n, cap; } Heap;
int *parent, *sz, *version;
long long *sum;

int find_set(int x) { if (parent[x] != x) parent[x] = find_set(parent[x]); return parent[x]; }
void push(Heap *h, Entry e) {
    if (h->n == h->cap) { h->cap = h->cap ? h->cap * 2 : 16; h->a = realloc(h->a, h->cap * sizeof(Entry)); if (!h->a) exit(1); }
    int i = h->n++;
    while (i > 0) { int p = (i - 1) / 2; if (h->a[p].sum >= e.sum) break; h->a[i] = h->a[p]; i = p; }
    h->a[i] = e;
}
Entry pop(Heap *h) {
    Entry top = h->a[0], last = h->a[--h->n];
    if (h->n) { int i = 0; while (2*i+1 < h->n) { int c = 2*i+1; if (c+1 < h->n && h->a[c+1].sum > h->a[c].sum) ++c; if (h->a[c].sum <= last.sum) break; h->a[i] = h->a[c]; i = c; } h->a[i] = last; }
    return top;
}
void record(Heap *h, int r, int K) { if (sz[r] <= K) push(h, (Entry){sum[r], r, version[r]}); }
void print_best(Heap *h, int K) {
    while (h->n) { Entry e = h->a[0]; if (parent[e.root] == e.root && version[e.root] == e.version && sz[e.root] <= K && sum[e.root] == e.sum) break; pop(h); }
    if (h->n) printf("Maximum eligible component weight: %lld\n", h->a[0].sum);
    else printf("No component has size <= %d.\n", K);
}
int main(void) {
    int V, E, K;
    if (scanf("%d%d%d", &V, &E, &K) != 3 || V <= 0 || E < 0 || K < 1) return 1;
    parent = malloc(V*sizeof(int)); sz = malloc(V*sizeof(int)); version = calloc(V,sizeof(int)); sum = malloc(V*sizeof(long long));
    if (!parent || !sz || !version || !sum) return 1;
    Heap h = {NULL, 0, 0};
    for (int i=0; i<V; ++i) { long long w; if (scanf("%lld", &w) != 1) return 1; parent[i]=i; sz[i]=1; sum[i]=w; record(&h,i,K); }
    for (int i=0; i<E; ++i) {
        int u,v; long long edgeWeight;
        if (scanf("%d%d%lld", &u,&v,&edgeWeight) != 3 || u<0 || u>=V || v<0 || v>=V) return 1;
        int a=find_set(u), b=find_set(v);
        if (a != b) {
            if (sz[a] < sz[b]) { int t=a; a=b; b=t; }
            parent[b]=a; sz[a]+=sz[b]; sum[a]+=sum[b]; ++version[a]; ++version[b];
            record(&h,a,K);
        }
        printf("After edge %d (%d, %d, weight %lld): ", i+1,u,v,edgeWeight);
        print_best(&h,K);
    }
    free(parent); free(sz); free(version); free(sum); free(h.a);
    return 0;
}
