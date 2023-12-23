#include<stdio.h>
#include<string.h>
#define MAXN 10
// #define debug
int findIdx(int lens[MAXN], int n){
    int minIdx = -1;
    for(int i = 0; i < n; i++){
        if(minIdx == -1 || lens[minIdx] > lens[i]){
            minIdx = i;
        }
    }
    return minIdx;
}
void splitAndMap(char*** ptr, char* str){
    char *start = strtok(str, "*");
    int lens[MAXN] = {0}, n = 0;
    int idxs[MAXN] = {0};
    while(ptr[n] != NULL) n++;
    while(start != NULL){
        int minIdx = findIdx(lens, n), len = strlen(start);
        ptr[minIdx][idxs[minIdx]] = start;
        #ifdef debug
        printf("ptr[%d][%d] %s\n", minIdx, lens[minIdx], ptr[minIdx][idxs[minIdx]]);
        #endif
        lens[minIdx] += len;
        idxs[minIdx] ++;
        start = strtok(NULL, "*");
    }
}