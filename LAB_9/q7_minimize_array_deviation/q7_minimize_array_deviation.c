/* Q7. Minimize deviation: normalize odd numbers by doubling, then repeatedly
   halve the current maximum while it is even. A max-heap is used.
   Complexity: O(n log n * log M), O(n) space. */
#include <stdio.h>
#define MAX 100000
long long h[MAX+5]; int sz=0;
void push(long long x) {
    int i=++sz;
    while(i>1 && h[i/2]<x){h[i]=h[i/2];i/=2;}
    h[i]=x;
}
long long pop(void) {
    long long out=h[1], x=h[sz--]; int i=1,c;
    while((c=i*2)<=sz){
        if(c+1<=sz && h[c+1]>h[c]) c++;
        if(x>=h[c]) break;
        h[i]=h[c];i=c;
    }
    h[i]=x; return out;
}
int main(void) {
    int n,i; long long x,mn=0,mx,dev,best;
    printf("Enter array size: ");
    if(scanf("%d",&n)!=1 || n<1 || n>MAX) return 1;
    for(i=0;i<n;i++){
        printf("Element %d: ",i+1);
        if(scanf("%lld",&x)!=1 || x<=0) return 1;
        if(x%2) x*=2;
        if(i==0 || x<mn) mn=x;
        push(x);
    }
    mx=h[1]; best=mx-mn;
    while(h[1]%2==0){
        mx=pop(); mx/=2;
        if(mx<mn) mn=mx;
        push(mx);
        dev=h[1]-mn;
        if(dev<best) best=dev;
    }
    printf("Minimum deviation = %lld\n",best);
    printf("Complexity: O(n log n log M) time, O(n) space.\n");
    return 0;
}
