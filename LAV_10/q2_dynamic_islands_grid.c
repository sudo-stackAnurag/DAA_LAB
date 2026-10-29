/* Q2: Number of Islands II using DSU and coordinate flattening.
   Input: R C K, followed by K positions r c (0-based). */
#include <stdio.h>
#include <stdlib.h>

int find_set(int parent[], int x) {
    if (parent[x] != x) parent[x] = find_set(parent, parent[x]);
    return parent[x];
}
int unite(int parent[], int size[], int a, int b) {
    a = find_set(parent, a); b = find_set(parent, b);
    if (a == b) return 0;
    if (size[a] < size[b]) { int t = a; a = b; b = t; }
    parent[b] = a; size[a] += size[b];
    return 1;
}

int main(void) {
    int R, C, K;
    if (scanf("%d%d%d", &R, &C, &K) != 3 || R <= 0 || C <= 0 || K < 0 || (long long)R*C > 100000000) return 1;
    int N = R * C;
    int *parent = malloc(N * sizeof(int));
    int *size = malloc(N * sizeof(int));
    unsigned char *land = calloc(N, sizeof(unsigned char));
    if (!parent || !size || !land) return 1;
    for (int i = 0; i < N; ++i) parent[i] = -1, size[i] = 0;

    int islands = 0;
    const int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
    for (int i = 0; i < K; ++i) {
        int r, c;
        if (scanf("%d%d", &r, &c) != 2 || r < 0 || r >= R || c < 0 || c >= C) {
            fprintf(stderr, "Invalid grid position. Use 0-based coordinates.\n");
            free(parent); free(size); free(land); return 1;
        }
        int id = r * C + c;
        if (!land[id]) {
            land[id] = 1; parent[id] = id; size[id] = 1; ++islands;
            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                    int nid = nr * C + nc;
                    if (land[nid] && unite(parent, size, id, nid)) --islands;
                }
            }
        }
        printf("After operation %d: %d island(s)\n", i + 1, islands);
    }
    free(parent); free(size); free(land);
    return 0;
}
