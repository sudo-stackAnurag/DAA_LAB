/* Q10. Greedy shortest-superstring exploration.
   Repeatedly merge the pair with maximum suffix-prefix overlap.
   This is a heuristic demonstration, NOT an exact solver and NOT a proof
   of a 2-approximation. Remove strings contained in another input string.
   Complexity: O(n^3 * L^2) simple upper bound, where L is maximum string length. */
#include <stdio.h>
#include <string.h>

#define MAXN 100
#define MAXS 1000

int overlap(const char *a,const char *b) {
    int la=(int)strlen(a),lb=(int)strlen(b),k;
    for(k=(la<lb?la:lb);k>0;k--)
        if(strncmp(a+la-k,b,k)==0) return k;
    return 0;
}
int main(void) {
    int n,i,j,besti,bestj,bestov;
    char s[MAXN][MAXS], merged[2*MAXS];
    printf("Enter number of strings: ");
    if(scanf("%d",&n)!=1 || n<1 || n>MAXN) return 1;
    for(i=0;i<n;i++){
        printf("String %d: ",i+1);
        if(scanf("%999s",s[i])!=1) return 1;
    }
    /* Remove strings already contained in another string. */
    for(i=0;i<n;i++) if(s[i][0]){
        for(j=0;j<n;j++) if(i!=j && s[j][0] && (strlen(s[i])<strlen(s[j]) || (strlen(s[i])==strlen(s[j]) && j<i)) &&
                              strstr(s[j],s[i])!=NULL) {
            s[i][0]='\0'; break;
        }
    }
    while(1){
        bestov=-1;besti=bestj=-1;
        for(i=0;i<n;i++) if(s[i][0])
            for(j=0;j<n;j++) if(i!=j && s[j][0]){
                int ov=overlap(s[i],s[j]);
                if(ov>bestov){bestov=ov;besti=i;bestj=j;}
            }
        if(besti==-1) break;
        strcpy(merged,s[besti]);
        strcat(merged,s[bestj]+bestov);
        strcpy(s[besti],merged);
        s[bestj][0]='\0';
    }
    for(i=0;i<n && !s[i][0];i++);
    if(i<n) printf("Greedy superstring = %s\n",s[i]);
    else printf("No result generated.\n");
    printf("Note: greedy heuristic only; the assignment describes this as an open research topic.\n");
    printf("Complexity: O(n^3 * L^2) conservative simple bound; O(nL) storage.\n");
    return 0;
}
