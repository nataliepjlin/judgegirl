#include<stdio.h>
#include<limits.h>
#define N 81
// #define debug
int max(int a, int b){
    return a * (a > b) + b * (a <= b);
}
int in(int l, int r, int c, int n){
    return (r >= 0 && r < n && c >= 0 && c < n
    && l >= 0 && l < n && r <= l && c <= l);
}
int getCount(int tower[N][N][N], int visited[N][N][N],
             int l, int r, int c, int n) {
    #ifdef debug
    printf("visiting (%d, %d, %d)\n", l, r, c);
    #endif

    int dl[] = {1, -1, 0, 0, 0, 0};
    int dr[] = {0, 0, 1, 0, -1, 0};
    int dc[] = {0, 0, 0, 1, 0, -1};

    visited[l][r][c] = 1;
    int count = 1; // Starting count as 1 for the current cell

    for (int d = 0; d < 6; d++) {
        int nl = l + dl[d], nr = r + dr[d], nc = c + dc[d];
        if (in(nl, nr, nc, n) && !visited[nl][nr][nc] &&
            tower[nl][nr][nc] == tower[l][r][c]) {
            count += getCount(tower, visited, nl, nr, nc, n);
        }
    }

    return count;
}
int main(){
    int n;
    int tower[N][N][N];
    scanf("%d", &n);
    for(int l = 0; l < n; l++){
        for(int r = 0; r <= l; r++){
            for(int c = 0; c <= l; c++){
                scanf("%d", &tower[l][r][c]);
            }
        }
    }

    int maxval = -1, maxcount = 0;
    int visited[N][N][N] = {{{0}}};
    for(int l = 0; l < n; l++){
        for(int r = 0; r <= l; r++){
            for(int c = 0; c <= l; c++){
                if(visited[l][r][c])
                    continue;
                int count = getCount(tower, visited, l, r, c, n);
                #ifdef debug
                printf("(%d, %d, %d), count = %d\n", l, r, c, count);
                #endif
                if(count > maxcount 
                || (count == maxcount && tower[l][r][c] > maxval)){
                    maxcount = count;
                    maxval = tower[l][r][c];
                    #ifdef debug
                    printf("change maxcount to %d\n", maxcount);
                    #endif
                }//change max
            }//col
        }//row
    }//layer
    printf("%d %d\n", maxval, maxcount);
}