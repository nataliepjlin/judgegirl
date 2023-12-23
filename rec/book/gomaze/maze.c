#include<stdio.h>
#define SIZE 100
int in(int r, int c, int n, int m){
    return(r >= 0 && r < n
    && c >= 0 && c < m);
}
int go(int maze[SIZE][SIZE], int step, int nowr, int nowc, int endr, int endc,
int n, int m){
    int dr[] = {1, 0, -1, 0};
    int dc[] = {0, 1, 0, -1};
    if(nowr == endr && nowc == endc)
        return 1;
    for(int d = 0; d < 4; d++){
        int nextr = nowr + dr[d];
        int nextc = nowc + dc[d];
        if(in(nextr, nextc, n, m) && maze[nextr][nextc] == 0){
            maze[nextr][nextc] = step;
            if(go(maze, step + 1, nextr, nextc, endr, endc, n, m))
                return 1;
            maze[nextr][nextc] = 0;
        }
    }
    return 0;
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int maze[SIZE][SIZE];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &maze[i][j]);
        }
    }
    int startr, startc;
    int endr, endc;
    scanf("%d%d%d%d", &startr, &startc, &endr, &endc);
    maze[startr][startc] = 1;
    go(maze, 2, startr, startc, endr, endc, n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%2d%c", maze[i][j], " \n"[j == m - 1]);
        }
    }
}