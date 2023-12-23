#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lock.h"
#define N 100
#define M 20
int numUnlocked(Locks *locks, bool lights[], int m);
void find(int idx, const int m, bool ans[], int *minpow, int *maxcnt, bool now[], int nowpow, Locks *locks){
    if(idx == m){
        int nowcnt = numUnlocked(locks, now, m);
        if(*maxcnt < nowcnt
        || (*maxcnt == nowcnt && *minpow > nowpow)){
            #ifdef debug
            printf("nowcnt = %d, nowpow = %d\n", nowcnt, nowpow);
            printf("maxcnt = %d, minpow = %d\n", *maxcnt, *minpow);
            #endif
            for(int i = 0; i < m; i++){
                #ifdef debug
                printf("%d", now[i]);
                #endif
                ans[i] = now[i];
            }
            #ifdef debug
            printf("\n\n");
            #endif
            *minpow = nowpow;
            *maxcnt = nowcnt;
        }
        return;
    }

    now[idx] = 0;
    find(idx + 1, m, ans, minpow, maxcnt, now, nowpow, locks);

    now[idx] = 1;
    find(idx + 1, m, ans, minpow, maxcnt, now, nowpow + (1 << idx), locks);
}
int main(){
    int n, m; scanf("%d%d", &m, &n);
    Locks *locks = malloc(sizeof(Locks));
    locks->n = n;
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &locks->lockSeq[i][0], &locks->lockSeq[i][1], &locks->lockSeq[i][2]);
        #ifdef debug
        printf("%d %d %d\n", locks->lockSeq[i][0], locks->lockSeq[i][1], locks->lockSeq[i][3]);
        #endif
    }
    bool now[M], ans[M];
    int unlocked[N] = {0};
    int maxcnt = 0, minpow = INT_MAX;
    find(0, m, ans, &minpow, &maxcnt, now, 0, locks);
    for(int i = 0; i < m; i++){
        printf("%d", ans[i]);
    }
    printf("\n");
    printf("%d\n%d\n", maxcnt, minpow);
}