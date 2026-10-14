/* Q9. Optimal alphabetic binary tree (Hu-Tucker objective).
   This uses exact interval dynamic programming rather than the Hu-Tucker
   greedy procedure. It minimizes sum(weight[i] * depth[i]).
   Complexity: O(n^3) time, O(n^2) space. */
#include <stdio.h>
#include <limits.h>
#define MAX 200
#define INF (LLONG_MAX/4)
long long w[MAX], pref[MAX], dp[MAX][MAX];
int split[MAX][MAX];

int main(void) {
    int n,i,len,l,r,k;
    printf("Enter number of ordered weights (max %d): ",MAX);
    if(scanf("%d",&n)!=1 || n<1 || n>MAX) return 1;
    for(i=0;i<n;i++){
        printf("Weight %d: ",i+1);
        if(scanf("%lld",&w[i])!=1 || w[i]<0) return 1;
        pref[i+1]=pref[i]+w[i];
        dp[i][i]=0; split[i][i]=i;
    }
    for(len=2;len<=n;len++){
        for(l=0;l+len<=n;l++){
            r=l+len-1; dp[l][r]=INF;
            for(k=l;k<r;k++){
                long long cost=dp[l][k]+dp[k+1][r]+(pref[r+1]-pref[l]);
                if(cost<dp[l][r]){dp[l][r]=cost;split[l][r]=k;}
            }
        }
    }
    printf("Minimum weighted path length = %lld\n",dp[0][n-1]);
    printf("Optimal alphabetic tree split structure:\n");
    /* Print split recursively using an explicit stack to avoid recursion complexity. */
    {
        int stL[2*MAX],stR[2*MAX],top=0;
        stL[top]=0;stR[top++]=n-1;
        while(top){
            l=stL[--top];r=stR[top];
            if(l==r) printf("Leaf: item %d, weight %lld\n",l+1,w[l]);
            else {
                k=split[l][r];
                printf("Interval [%d,%d] splits after item %d\n",l+1,r+1,k+1);
                stL[top]=k+1;stR[top++]=r;
                stL[top]=l;stR[top++]=k;
            }
        }
    }
    printf("Complexity: O(n^3) time, O(n^2) space. This is an exact DP alternative, not Hu-Tucker greedy.\n");
    return 0;
}
