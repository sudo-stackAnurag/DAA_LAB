/* Q1: Online graph bipartiteness testing using DSU with parity.
   Input: V E, followed by E edges u v (vertices are 0-based).
   Each edge is accepted if it preserves bipartiteness; otherwise skipped. */
#include <stdio.h>
#include <stdlib.h>

int *parent, *sz, *parity;

int find_set(int x) {
    if (parent[x] == x) return x;
    int p = parent[x];
    parent[x] = find_set(p);
    parity[x] ^= parity[p];
    return parent[x];
}

int add_edge(int u, int v) {
    int ru = find_set(u), pu = parity[u];
    int rv = find_set(v), pv = parity[v];
    if (ru == rv) return (pu ^ pv) == 1;

    if (sz[ru] < sz[rv]) {
        int t = ru; ru = rv; rv = t;
        t = pu; pu = pv; pv = t;
    }
    parent[rv] = ru;
    /* Endpoints must have opposite colors. */
    parity[rv] = pu ^ pv ^ 1;
    sz[ru] += sz[rv];
    return 1;
}

int main(void) {
    int V, E;
    if (scanf("%d%d", &V, &E) != 2 || V <= 0 || E < 0) return 1;
    parent = malloc(V * sizeof(int)); sz = malloc(V * sizeof(int));
    parity = calloc(V, sizeof(int));
    if (!parent || !sz || !parity) return 1;
    for (int i = 0; i < V; ++i) parent[i] = i, sz[i] = 1;

    for (int i = 0; i < E; ++i) {
        int u, v;
        if (scanf("%d%d", &u, &v) != 2 || u < 0 || u >= V || v < 0 || v >= V) {
            fprintf(stderr, "Invalid edge input. Use vertices 0 to V-1.\n");
            free(parent); free(sz); free(parity); return 1;
        }
        if (add_edge(u, v))
            printf("Edge (%d, %d): ACCEPTED; graph remains bipartite.\n", u, v);
        else
            printf("Edge (%d, %d): REJECTED; would violate bipartiteness.\n", u, v);
    }
    free(parent); free(sz); free(parity);
    return 0;
}
