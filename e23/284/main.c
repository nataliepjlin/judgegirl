#include <stdio.h>
#include "n.h"
 
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        GiantUnsignedInt giantNum;
        for (int i = 0; i<n; i++)
            scanf("%lu", &giantNum.array[i]);
        giantNum.n = n;
        // printf("main, gn = %d\n", giantNum.n);
        printf("%d\n", numZeroBits(&giantNum));
    }
    return 0;
}