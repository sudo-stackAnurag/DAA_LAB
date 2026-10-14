/* Q5. Candy distribution with left-to-right and right-to-left passes.
   Complexity: O(n) time, O(n) space. */
#include <stdio.h>
#define MAX 100000
int main(void) {
    int n, r[MAX], c[MAX], i;
    long long total=0;
    printf("Enter number of children: ");
    if (scanf("%d",&n)!=1 || n<1 || n>MAX) return 1;
    for (i=0;i<n;i++) {
        printf("Rating %d: ",i+1);
        if (scanf("%d",&r[i])!=1) return 1;
        c[i]=1;
    }
    for (i=1;i<n;i++) if (r[i]>r[i-1]) c[i]=c[i-1]+1;
    for (i=n-2;i>=0;i--) if (r[i]>r[i+1] && c[i]<=c[i+1]) c[i]=c[i+1]+1;
    for (i=0;i<n;i++) { total+=c[i]; printf("Child %d: %d candy/candies\n",i+1,c[i]); }
    printf("Minimum total candies = %lld\n",total);
    printf("Complexity: O(n) time, O(n) space.\n");
    return 0;
}
