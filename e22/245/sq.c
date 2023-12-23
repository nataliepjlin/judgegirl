#include<stdio.h>
#include<stdlib.h>
#define N 6
// #define debug
int in(int r, int c, int n){
    return(r >= 0 && r < n && c >= 0 && c < n);
}
int place(int idx, int n, int ans[N][N], int used[N], int sq[][4], int *solved){
    if(idx == n * n){
        for(int i = 0; i < n * n; i++){
            printf("%d%c", ans[i / n][i % n], " \n"[i % n == n - 1]);
        }
        *solved = 1;
        #ifdef debug
        printf("\n");
        #endif
        return 1;
    }
    int ar = idx / n, ac = idx % n;
    for(int s = 0; s < n * n; s++){
        if(!used[s] 
        && (!in(ar, ac - 1, n) || (sq[ans[ar][ac - 1]][2] == sq[s][0]))
        && (!in(ar - 1, ac, n) || (sq[ans[ar - 1][ac]][3] == sq[s][1]))){
            used[s] = 1;
            ans[ar][ac] = s;
            #ifdef debug
            printf("place %dth sq to ans[%d][%d]\n", s, ar, ac);
            #endif
            if(place(idx + 1, n, ans, used, sq, solved))
                return 1;
            used[s] = 0;
        }
    }
    return 0;
}
int main(){
    int n;
    while(scanf("%d", &n) == 1){
        #ifdef debug
        printf("\nn = %d\n", n);
        #endif
        int sq[N * N][4] = {{0}};
        for(int i = 0; i < n * n; i++){
            scanf("%d%d%d%d", &sq[i][0], &sq[i][1], &sq[i][2], &sq[i][3]);
        }
        int ans[N][N] = {{0}};
        int used[N * N] = {0};
        int solved = 0;
        place(0, n, ans, used, sq, &solved);
        if(!solved) printf("no solution\n");
    }
}