/* Q2. Huffman coding and canonical Huffman codebook.
   Complexity: O(n^2) for simple minimum-node selection, O(n) space. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    long long freq;
    int left, right, parent;
    char symbol;
} Node;

typedef struct {
    char symbol;
    long long freq;
    int length;
    char code[MAX + 1];
} Code;

int main(void) {
    int n, i, j, nodes;
    Node tree[2 * MAX];
    Code codes[MAX], temp;
    char symbol;
    long long freq;

    printf("Enter number of symbols (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) return 1;

    nodes = n;
    for (i = 0; i < n; i++) {
        printf("Enter symbol and frequency: ");
        if (scanf(" %c %lld", &symbol, &freq) != 2 || freq < 0) return 1;
        for (j = 0; j < i; j++)
            if (codes[j].symbol == symbol) {
                printf("Symbols must be unique.\n");
                return 1;
            }
        codes[i].symbol = symbol;
        codes[i].freq = freq;
        codes[i].length = 0;
        codes[i].code[0] = '\0';
        tree[i].freq = freq; tree[i].left = tree[i].right = tree[i].parent = -1;
        tree[i].symbol = symbol;
    }

    if (n == 1) {
        codes[0].length = 1;
    } else {
        while (1) {
            int a = -1, b = -1;
            for (i = 0; i < nodes; i++) if (tree[i].parent == -1) {
                if (a == -1 || tree[i].freq < tree[a].freq) { b = a; a = i; }
                else if (b == -1 || tree[i].freq < tree[b].freq) b = i;
            }
            if (b == -1) break;
            tree[nodes].freq = tree[a].freq + tree[b].freq;
            tree[nodes].left = a; tree[nodes].right = b; tree[nodes].parent = -1;
            tree[nodes].symbol = 0;
            tree[a].parent = tree[b].parent = nodes;
            nodes++;
        }

        for (i = 0; i < n; i++) {
            int cur = i, len = 0;
            while (tree[cur].parent != -1) { len++; cur = tree[cur].parent; }
            codes[i].length = len;
        }
    }

    /* Sort by length, then symbol for deterministic canonical ordering. */
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (codes[j].length < codes[i].length ||
               (codes[j].length == codes[i].length &&
                (unsigned char)codes[j].symbol < (unsigned char)codes[i].symbol)) {
                temp = codes[i]; codes[i] = codes[j]; codes[j] = temp;
            }

    {
        unsigned long long current = 0;
        int previousLength = codes[0].length;
        for (i = 0; i < n; i++) {
            if (i == 0) current = 0;
            else {
                current++;
                current <<= (codes[i].length - previousLength);
                previousLength = codes[i].length;
            }
            for (j = codes[i].length - 1; j >= 0; j--)
                codes[i].code[codes[i].length - 1 - j] =
                    ((current >> j) & 1ULL) ? '1' : '0';
            codes[i].code[codes[i].length] = '\0';
        }
    }

    printf("\nCanonical Huffman codebook (length, then symbol):\n");
    for (i = 0; i < n; i++)
        printf("%c  frequency=%lld  length=%d  code=%s\n",
               codes[i].symbol, codes[i].freq, codes[i].length, codes[i].code);
    printf("Complexity: O(n^2) time, O(n) space.\n");
    return 0;
}
