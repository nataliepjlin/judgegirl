#include <stdint.h>
#include<stdio.h>
#define ARRAYSIZE 1000
 
typedef struct giantUnsignedInt {
    uint64_t array[ARRAYSIZE];
    int n;
} GiantUnsignedInt;
int numZeroBits(GiantUnsignedInt *giantNum){
    int maxcnt = 0;
    int cnt = 0;
    for(int i = 0; i < giantNum->n; i++){
        for(int j = 63; j >= 0; j--){
            int num = ((giantNum->array[i] >> j) & 1);
            #ifdef debug
            printf("%d", num);
            #endif
            cnt += (!num);
            cnt *= (!num);
            if(maxcnt < cnt){
                maxcnt = cnt;
            }
        }
        #ifdef debug
        printf("\n");
        #endif
    }
    return maxcnt;
}