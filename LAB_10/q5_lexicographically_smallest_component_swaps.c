/* Q5: Lexicographically smallest permutation using swaps along graph edges.
   Input: n m, permutation A[0..n-1], then m edges u v (0-based positions). */
#include <stdio.h>
#include <stdlib.h>

typedef struct { int root, index; } Member;
int cmp_member(const void *x, const void *y) {
    const Member *a=x, *b=y;
    if (a->root != b->root) return (a->root > b->root) - (a->root < b->root);
    return (a->index > b->index) - (a->index < b->index);
}
int cmp_int(const void *x, const void *y) { int a=*(const int*)x,b=*(const int*)y; return (a>b)-(a<b); }
int find_set(int parent[], int x) { if (parent[x]!=x) parent[x]=find_set(parent,parent[x]); return parent[x]; }
void unite(int parent[], int size[], int a, int b) {
    a=find_set(parent,a); b=find_set(parent,b); if (a==b) return;
    if (size[a]<size[b]) { int t=a; a=b; b=t; }
    parent[b]=a; size[a]+=size[b];
}
int main(void) {
    int n,m;
    if (scanf("%d%d",&n,&m)!=2 || n<=0 || m<0) return 1;
    int *A=malloc(n*sizeof(int)), *parent=malloc(n*sizeof(int)), *size=malloc(n*sizeof(int));
    Member *members=malloc(n*sizeof(Member));
    int *values=malloc(n*sizeof(int));
    if (!A||!parent||!size||!members||!values) return 1;
    for (int i=0;i<n;++i) { if (scanf("%d",&A[i])!=1) return 1; parent[i]=i; size[i]=1; }
    for (int i=0;i<m;++i) { int u,v; if (scanf("%d%d",&u,&v)!=2 || u<0||u>=n||v<0||v>=n) return 1; unite(parent,size,u,v); }
    for (int i=0;i<n;++i) members[i]=(Member){find_set(parent,i),i};
    qsort(members,n,sizeof(Member),cmp_member);
    int start=0;
    while (start<n) {
        int end=start+1;
        while (end<n && members[end].root==members[start].root) ++end;
        for (int j=start;j<end;++j) values[j-start]=A[members[j].index];
        qsort(values,end-start,sizeof(int),cmp_int);
        for (int j=start;j<end;++j) A[members[j].index]=values[j-start];
        start=end;
    }
    printf("Lexicographically smallest permutation: ");
    for (int i=0;i<n;++i) printf("%d%s",A[i],i+1==n?"\n":" ");
    free(A); free(parent); free(size); free(members); free(values);
    return 0;
}
