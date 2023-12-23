#include<stdio.h>
#define N 4
// #define debug
int in(int r, int c){
    return(r >= 0 && r < N && c >= 0 && c < N);
}
int cnt(int puz[N][N]){
    int ct = 0;
    for(int i = 0; i < N * N; i++){
        int r = i / N, c = i % N;
        ct += (puz[r][c] != (i + 1) % (N * N));
    }
    return ct;
}
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
int solve(int k, int puz[N][N], int zr, int zc, int last){
    int wa = cnt(puz);
    if(!wa) return 1;
    if(k < 0 || k < (wa - 1)) return 0;
 
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    for(int d = 0; d < 4; d++){
        int nr = zr + dr[d], nc = zc + dc[d];
        if(((d + 2) % 4) != last && in(nr, nc)){
            swap(&puz[nr][nc], &puz[zr][zc]);
            if(solve(k - 1, puz, nr, nc, d))
                return 1;
            swap(&puz[nr][nc], &puz[zr][zc]);
        }
    }
    return 0;
}
int main(){
    int k;
    int puz[N][N];
    int zr, zc;
    while(scanf("%d", &k) == 1){
        int wrong = 0;
        int ct = 1;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%d", &puz[i][j]);
                if(!puz[i][j]){
                    zr = i, zc = j;
                }
            }
        }
        printf("%d\n", solve(k, puz, zr, zc, -1));
    }
}