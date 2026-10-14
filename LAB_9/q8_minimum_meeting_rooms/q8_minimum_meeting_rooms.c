/* Q8. Minimum meeting rooms.
   Sort start and end times separately and sweep them.
   Meetings whose end time equals a new start are treated as non-overlapping.
   Complexity: O(n log n) time, O(n) space. */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
int cmp(const void *a,const void *b){
    int x=*(const int*)a,y=*(const int*)b;
    return (x>y)-(x<y);
}
int main(void){
    int n,i,s[MAX],e[MAX],rooms=0,maxRooms=0,si=0,ei=0;
    printf("Enter number of meetings: ");
    if(scanf("%d",&n)!=1 || n<1 || n>MAX) return 1;
    for(i=0;i<n;i++){
        printf("Enter start and end for meeting %d: ",i+1);
        if(scanf("%d %d",&s[i],&e[i])!=2 || e[i]<s[i]) return 1;
    }
    qsort(s,n,sizeof(int),cmp); qsort(e,n,sizeof(int),cmp);
    while(si<n){
        if(si<n && (ei>=n || s[si]<e[ei])) {
            rooms++; si++;
            if(rooms>maxRooms) maxRooms=rooms;
        } else {
            rooms--; ei++;
        }
    }
    printf("Minimum number of meeting rooms = %d\n",maxRooms);
    printf("Complexity: O(n log n) time, O(n) space.\n");
    return 0;
}
