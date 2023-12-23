#include<stdio.h>
#define MAXN 1000000
// #define DEBUG
int max(int a, int b){
    return a * (a > b) + b * (a <= b);
}
int min(int a, int b){
    return a * (a < b) + b * (a >= b);
}
void loops(int N, int *A, int *B[], int ans[4]){
    int visited[MAXN] = {0};
    ans[0] = 0, ans[1] = MAXN, ans[2] = 0, ans[3] = MAXN;
    for(int i = 0; i < N; i++){
        if(visited[i]) continue;
        int nowMax = A[i], nowMin = A[i], nowLen = 1;
        int *ptr = B[i];
        visited[i] = 1;
        while(ptr != &A[i]){
            int idx = ptr - A;
            visited[idx] = 1;
            nowMax = max(nowMax, *ptr);
            nowMin = min(nowMin, *ptr);
            #ifdef DEBUG
            printf("idx = %d, nowMax = %d, nowMin = %d\n", idx, nowMax, nowMin);
            #endif
            ptr = B[idx];
            nowLen ++;
        }//looping
        if(ans[0] < nowLen || ans[0] == nowLen && ans[2] < nowMax){
            ans[0] = nowLen;
            ans[2] = nowMax;
        }
        if(ans[1] > nowLen || ans[1] == nowLen && ans[3] > nowMin){
            ans[1] = nowLen;
            ans[3] = nowMin;
        }
        #ifdef DEBUG
        printf("\n");
        #endif
    }
}