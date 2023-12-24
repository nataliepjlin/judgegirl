#include<stdio.h>
#include "hanoi.h"
void initialize(struct hanoi *hn, int n){
    hn->cnt[0] = n, hn->cnt[1] = 0, hn->cnt[2] = 0;
    for(int i = 0; i < n; i++){
        hn->arr[0][i] = (n - 1) - i;
    }
}
void moveHanoi(struct hanoi *hn, int src, int dst){
    hn->arr[dst][hn->cnt[dst]] = hn->arr[src][hn->cnt[src] - 1];
    hn->cnt[src] -= 1, hn->cnt[dst] += 1;
}
void printHanoi(struct hanoi *hn){
    for(int i = 0; i < 3; i++){
        printf("%d:", i);
        for(int j = 0; j < hn->cnt[i]; j++){
            printf(" %d", hn->arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}