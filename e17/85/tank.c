#include<stdio.h>
#include<assert.h>
#define MAXN 500
#define MAXM 500
// #define debug
void printMap(int map[MAXN][MAXM], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
}
int inMap(int r, int c, int n, int m){
    return (r >= 0 && r < n && c >= 0 && c < m);
}
int noHit(int r, int c, int dr, int dc, int map[MAXN][MAXM], int l, int w){
    int no = 1;
    int count = 0;
    if(dr && dc){
        count += (map[r + (l - 1) + dr][(c + w - 1) + dc] == 2);
        #ifdef debug
        printf("init count = %d\n", count);
        #endif
        for(int col = 1; col < w && no; col ++){
            count += (map[r + (l - 1) + dr][c + col] == 2);
            #ifdef debug
            printf("checking map[%d][%d] = %d, now count = %d\n", r + (l - 1) + dr, c + col, map[r + (l - 1) + dr][c + col],count);
            #endif
            if(count > 1) no = 0;
        }
        #ifdef debug
        printf("\n");
        #endif
        for(int row = 1; row < l && no; row ++){
            count += (map[r + row][(c + w - 1) + dc] == 2);
            #ifdef debug
            printf("checking map[%d][%d] = %d, now count = %d\n", r + row, (c + w - 1) + dc, map[r + row][(c + w - 1) + dc], count);
            #endif
            if(count > 1) no = 0;
        }
    } 
    else if(dr){
        for(int col = 0; col < w && no; col ++){
            count += (dr > 0) ? (map[r + (l - 1) + dr][c + col] == 2) : 
            (map[r + dr][c + col] == 2);
            #ifdef debug
            (dr > 0) ? printf("checking map[%d][%d] = %d, now count = %d\n", r + (l - 1) + dr, c + col, map[r + (l - 1) + dr][c + col],count)
            : printf("checking map[%d][%d] = %d, now count = %d\n", r + dr, c + col, map[r + dr][c + col],count);
            #endif
            if(count > 1) no = 0;
        }
    }
    else if(dc){
        for(int row = 0; row < l && no; row ++){
            count += (dc > 0) ? (map[r + row][(c + w - 1) + dc] == 2) 
            : (map[r + row][c + dc] == 2);
            #ifdef debug
            (dc > 0) ? printf("checking map[%d][%d] = %d, now count = %d\n", r + row, (c + w - 1) + dc, map[r + row][(c + w - 1) + dc], count)
            : printf("checking map[%d][%d] = %d, now count = %d\n", r + row, c + dc, map[r + row][c + dc], count);
            #endif
            if(count > 1) no = 0;
        }
    }
    return no;
}
int main(){
    int map[MAXN][MAXM] = {{0}};
    int n, m, l, w;
    scanf("%d%d%d%d", &n, &m, &l, &w);
    for(int i = 0; i < l; i++){
        for(int j = 0; j < w; j++){
            map[i][j] = 1;
        }
    }
    int o, y, x;
    scanf("%d", &o);
    for(int i = 0; i < o; i++){
        scanf("%d%d", &x, &y);
        map[y][x] = 2;
    }
    int cmd;
    int nowr = 0, nowc = 0;
    int dr[] = {0, 0, 1, 0, -1, 1};
    int dc[] = {0, 1, 0, -1, 0, 1};
    while(scanf("%d", &cmd) != EOF){
        // assert(cmd != 5);
        #ifdef debug
        printf("cmd = %d\n", cmd);
        #endif
        if(cmd == 0) printMap(map, n, m);
        else if(cmd == 1 
        && inMap((nowr + l - 1) + dr[cmd], (nowc + w - 1) + dc[cmd], n, m)
        && noHit(nowr, nowc, dr[cmd], dc[cmd], map, l, w)){
            for(int r = 0; r < l; r++){
                map[r + nowr][nowc] = 0;
                map[r + nowr][(nowc + w - 1) + dc[cmd]] = 1;
            }
            nowr += dr[cmd];
            nowc += dc[cmd];
            #ifdef debug
            printf("nowr = %d, nowc = %d\n", nowr, nowc);
            printMap(map, n, m);
            #endif
        }
        else if(cmd == 2
        && inMap((nowr + l - 1) + dr[cmd], (nowc + w - 1) + dc[cmd], n, m)
        && noHit(nowr, nowc, dr[cmd], dc[cmd], map, l, w)){
            for(int c = 0; c < w; c++){
                map[nowr][c + nowc] = 0;
                map[(nowr + l - 1) + dr[cmd]][c + nowc] = 1;
            }
            nowr += dr[cmd];
            nowc += dc[cmd];
            #ifdef debug
            printf("nowr = %d, nowc = %d\n", nowr, nowc);
            printMap(map, n, m);
            #endif
        }
        else if(cmd == 3
        && inMap(nowr + dr[cmd], nowc + dc[cmd], n, m)
        && noHit(nowr, nowc, dr[cmd], dc[cmd], map, l, w)){
            for(int r = 0; r < l; r++){
                map[r + nowr][(nowc + w - 1)] = 0;
                map[r + nowr][nowc + dc[cmd]] = 1;
            }
            nowr += dr[cmd];
            nowc += dc[cmd];
            #ifdef debug
            printf("nowr = %d, nowc = %d\n", nowr, nowc);
            printMap(map, n, m);
            #endif
        }
        else if(cmd == 4
        && inMap(nowr + dr[cmd], nowc + dc[cmd], n, m)
        && noHit(nowr, nowc, dr[cmd], dc[cmd], map, l, w)){
            for(int c = 0; c < w; c++){
                map[(nowr + l - 1)][c + nowc] = 0;
                map[nowr +dr[cmd]][c + nowc] = 1;
            }
            nowr += dr[cmd];
            nowc += dc[cmd];
            #ifdef debug
            printf("nowr = %d, nowc = %d\n", nowr, nowc);
            printMap(map, n, m);
            #endif
        }
        else if(cmd == 5
        && inMap((nowr + l - 1) + dr[cmd], (nowc + w - 1) + dc[cmd], n, m)
        && noHit(nowr, nowc, dr[cmd], dc[cmd], map, l, w)){
            for(int r = 1; r < l; r++){
                map[r + nowr][nowc] = 0;
                map[r + nowr][(nowc + w - 1) + dc[cmd]] = 1;
            }
            for(int c = 1; c < w; c++){
                map[nowr][c + nowc] = 0;
                map[(nowr + l - 1) + dr[cmd]][c + nowc] = 1;
            }
            map[nowr][nowc] = 0; 
            map[(nowr + l - 1) + dr[cmd]][(nowc + w - 1) + dc[cmd]] = 1;

            nowr += dr[cmd];
            nowc += dc[cmd];
            #ifdef debug
            printf("nowr = %d, nowc = %d\n", nowr, nowc);
            printMap(map, n, m);
            #endif
        }
    }
    return 0;
}