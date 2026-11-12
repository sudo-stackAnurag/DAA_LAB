/* Q4: Vertex deletions handled in reverse using DSU.
   Input: V, V vertex weights, VxV adjacency matrix (0/1), then deletion order P.
   Vertices are 0-based. Output maximum component sum after each deletion. */
#include <stdio.h>
#include <stdlib.h>

int find_set(int parent[], int x) { if (parent[x] != x) parent[x] = find_set(parent, parent[x]); return parent[x]; }
void unite(int parent[], int size[], long long sum[], int a, int b) {
    a=find_set(parent,a); b=find_set(parent,b); if (a==b) return;
    if (size[a]<size[b]) { int t=a; a=b; b=t; }
    parent[b]=a; size[a]+=size[b]; sum[a]+=sum[b];
}
long long maximum(int V, unsigned char active[], int parent[], long long sum[]) {
    int found=0; long long best=0;
    for (int i=0;i<V;++i) if (active[i] && find_set(parent,i)==i) {
        if (!found || sum[i]>best) best=sum[i];
        found=1;
    }
    return found ? best : 0;
}
int main(void) {
    int V;
    if (scanf("%d", &V)!=1 || V<=0 || V>5000) return 1;
    long long *weight=malloc(V*sizeof(long long));
    unsigned char *adj=calloc((size_t)V*V,1), *active=calloc(V,1);
    int *parent=malloc(V*sizeof(int)), *size=malloc(V*sizeof(int)), *order=malloc(V*sizeof(int));
    long long *sum=malloc(V*sizeof(long long)), *ans=malloc(V*sizeof(long long));
    if (!weight||!adj||!active||!parent||!size||!order||!sum||!ans) return 1;
    for (int i=0;i<V;++i) if (scanf("%lld", &weight[i])!=1) return 1;
    for (int i=0;i<V;++i) for (int j=0;j<V;++j) { int x; if (scanf("%d",&x)!=1) return 1; adj[(size_t)i*V+j]=(x!=0); }
    for (int i=0;i<V;++i) if (scanf("%d",&order[i])!=1 || order[i]<0 || order[i]>=V) return 1;
    for (int i=0;i<V;++i) parent[i]=i, size[i]=1, sum[i]=weight[i];

    for (int i=V-1;i>=0;--i) {
        ans[i]=maximum(V,active,parent,sum);
        int u=order[i]; active[u]=1;
        for (int v=0;v<V;++v) if (active[v] && adj[(size_t)u*V+v]) unite(parent,size,sum,u,v);
    }
    for (int i=0;i<V;++i) printf("After deleting vertex %d: maximum component sum = %lld\n", order[i], ans[i]);
    free(weight); free(adj); free(active); free(parent); free(size); free(order); free(sum); free(ans);
    return 0;
}
