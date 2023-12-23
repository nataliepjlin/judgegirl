#include<stdio.h>
#define N 4
int counter(int bd[N][N], int n){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cnt += (bd[i][j]);
        }
    }
    return cnt;
}
void printans(int ans[], int a){
    for(int i = 0; i < a; i++){
        printf("%d%c", ans[i], " \n"[i == a - 1]);
    }
    return;
}
int in(int r, int c, int n){
    return(r >= 0 && r < n && c >= 0 && c < n);
}
void reverse(int bd[N][N], int r, int c, int n){
    bd[r][c] ^= 1; 
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i], nc = c + dc[i];
        if(in(nr, nc, n)){
            bd[nr][nc] ^= 1;
        }
    }
}
void solve(int idx, int visited[N][N],
int bd[N][N], int n, int nowans[], int nowa, int ans[], int *a){
    if(nowa >= *a)
        return;
    int cnt = counter(bd, n);
    if(!cnt){
        for(int i = 0; i < nowa; i++){
            ans[i] = nowans[i];
        }
        *a = nowa;
        return;
    }
    if(idx >= n * n)
        return;
        
    int r = idx / n, c = idx % n;
    if(!visited[r][c]){
        visited[r][c] = 1;
        reverse(bd, r, c, n);
        nowans[nowa] = idx;
        solve(idx + 1, visited, bd, n, nowans, nowa + 1, ans, a);
        reverse(bd, r, c, n); 
        visited[r][c] = 0;
        
    }
    solve(idx + 1, visited, bd, n, nowans, nowa, ans, a);
}
int main(){
    int bd[N][N] = {{0}};
    int n; scanf("%d", &n);
    int pos;
    while(scanf("%d", &pos) == 1){
        int r = pos / n, c = pos % n;
        bd[r][c] = 1;
    }
    int visited[N][N] = {{0}};
    int nowans[N * N], a = N * N + 1;
    int ans[N * N];
    solve(0, visited, bd, n, nowans, 0, ans, &a);
    printans(ans, a);
}