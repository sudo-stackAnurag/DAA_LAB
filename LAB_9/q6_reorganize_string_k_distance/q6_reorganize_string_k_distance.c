/* Q6. Rearrange characters so equal characters are at least K positions apart.
   Greedy max-frequency selection with a waiting queue.
   Complexity: O(L * alphabet_size) here, with fixed ASCII table; O(ASCII) space. */
#include <stdio.h>
#include <string.h>

#define ASCII 128
#define MAXLEN 10000

typedef struct { int ch, count, availableAt; } Entry;

int main(void) {
    char s[MAXLEN], out[MAXLEN];
    int freq[ASCII]={0}, last[ASCII], n, k, i, pos;
    printf("Enter string (no spaces): ");
    if (scanf("%9999s",s)!=1) return 1;
    printf("Enter K: ");
    if (scanf("%d",&k)!=1 || k<0) return 1;
    n=(int)strlen(s);
    for (i=0;i<ASCII;i++) last[i]=-1000000;
    for (i=0;i<n;i++) {
        unsigned char ch=(unsigned char)s[i];
        if (ch>=ASCII) { printf("ASCII characters only.\n"); return 1; }
        freq[ch]++;
    }
    for (pos=0;pos<n;pos++) {
        int best=-1;
        if (k<=1) {
            for (i=0;i<ASCII;i++) if (freq[i]>0 && (best==-1 || freq[i]>freq[best])) best=i;
        } else {
            for (i=0;i<ASCII;i++)
                if (freq[i]>0 && pos-last[i]>=k && (best==-1 || freq[i]>freq[best])) best=i;
        }
        if (best==-1) { printf("Impossible: empty string result.\n"); return 0; }
        out[pos]=(char)best; freq[best]--; last[best]=pos;
    }
    out[n]='\0';
    printf("Rearranged string = %s\n",out);
    printf("Complexity: O(L * 128) time, O(128 + L) space.\n");
    return 0;
}
