#include "lock.h"
#include <stdio.h>
#include <stdlib.h>
Locks* init(int lockSeq[][3], int n){
    Locks *locks = malloc(sizeof(Locks));
    locks->n = n;
    #ifdef debug
    printf("locks->n = %d\n", locks->n);
    #endif
    for(int i = 0; i < n; i++){
        locks->lockSeq[i][0] = lockSeq[i][0];
        locks->lockSeq[i][1] = lockSeq[i][1];
        locks->lockSeq[i][2] = lockSeq[i][2];
    }
    return locks;
}
int numUnlocked(Locks *locks, bool lights[], int m){
    int cnt = 0;
    for(int i = 0; i < locks->n; i++){
        int f = 0;
        for(int j = 0; j < 3 && !f; j++){
            int k = abs(locks->lockSeq[i][j]) - 1, p = (locks->lockSeq[i][j] > 0);
            if(!(p ^ lights[k])){
                cnt++;
                f = 1;
            }
        }
    }
    return cnt;
}