#include<stdio.h>
// #define debug
#define MAXN 1000000
int max(int a, int b){
    return (a > b) * a + (a <= b) * b;
}
int min(int a, int b){
    return (a < b) * a + (a >= b) * b;
}
void loops(int N, int *A, int *B[], int ans[4]){
    ans[0] = ans[2] = 0;
    ans[1] = ans[3] = MAXN;
    int visited[MAXN] = {0};
    for(int i = 0; i < N; i++){
        if(visited[i]) continue;
        #ifdef debug
        printf("\ni = %d\n", i);
        #endif
        int idx = B[i] - A;
        int count = 1, nowmax = A[i], nowmin = A[i];
        #ifdef debug
        printf("init count = %d, idx = %d\n", count, idx);
        #endif
        while(idx != i){
            visited[idx] = 1;
            count ++;
            nowmax = max(nowmax, A[idx]);
            nowmin = min(nowmin, A[idx]);
            idx = B[idx] - A;
            #ifdef debug
            printf("count = %d, idx = %d\n", count, idx);
            #endif
        }
        if(count > ans[0]
        || count == ans[0] && nowmax > ans[2]){
            ans[0] = count;
            ans[2] = nowmax;
        }
        if(count < ans[1]
        || count == ans[1] && nowmin < ans[3]){
            ans[1] = count;
            ans[3] = nowmin;
        }
    }
}