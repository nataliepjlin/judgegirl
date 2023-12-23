#include<stdio.h>
#include<stdlib.h>
#define N 9
// #define debug
int in(int r, int c){
    return(r >= 0 && r < N && c >= 0 && c < N);
}
int valid(int map[N][N], int ans[N][N], int idx){
    int dr[] = {0, 0, 0, 1, 1, 1, -1, -1, -1};
    int dc[] = {0, 1, -1, 0, 1, -1, 0, 1, -1};
    int R = idx / N, C = idx % N;
    for(int i = 0; i <= idx; i++){
        int r = i / N, c = i % N;
        int count = 0;
        for(int d = 0; d < 9; d++){
            int nr = r + dr[d], nc = c + dc[d];
            count += (in(nr, nc) && ans[nr][nc]);
        }
        if((((r < R && c < C) || idx == N * N - 1) && count != map[r][c])
        || count > map[r][c])
            return 0;
    }
    return 1;
}
void solve(int map[N][N], int ans[N][N], int idx, int r, int c){
    if(idx == N * N){
        for(int i = 0; i < N * N; i++){
            printf("%d%c", ans[i / N][i % N], " \n"[i % N == N - 1]);
        }
        exit(0);
    }
    ans[r][c] = 1;
    if(valid(map, ans, idx))
        solve(map, ans, idx + 1, (idx + 1) / N, (idx + 1) % N);
    ans[r][c] = 0;
    if(valid(map, ans, idx))
        solve(map, ans, idx + 1, (idx + 1) / N, (idx + 1) % N);
}
int main(){
    int map[N][N], ans[N][N] = {0};
    for(int i = 0; i < N * N; i++){
        scanf("%d", &map[i / N][i % N]);
    }
    solve(map, ans, 0, 0, 0);
    
    printf("no solution\n");
}
