#include <stdio.h>
// #define debug
#define MAXN 100
#define MAXP 8
int oob(int r, int c, int n){
    return (r < 0 || r > n - 1 || c < 0 || c > n - 1);
}
int validMoveNum(int r, int c, int n, int map[100][100]){
    int move[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    int p = 0;
    //(r, c): knight's location, n: size
    if(map[r][c] || oob(r, c, n)) p = -1;
    for(int i = 0; i < 8 && p != -1; i++){
        p += (!map[r + move[i][0]][c + move[i][1]] 
        && !oob(r + move[i][0], c + move[i][1], n));
    }
    return p;
}
int nextMove(int r, int c, int n, int map[100][100]){
    int move[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    int p[8];
    int minp = MAXP, minj = -1;
    for(int j=0; j<8; j++){
        p[j] = validMoveNum(r+move[j][0], c+move[j][1], n, map); 
        if(minp > p[j] && p[j] != -1){
            minp = p[j];
            minj = j;
        } 
    }
    return minj;
}
int main(){
    int n, m;
    int stepCount[MAXN * MAXN] = {0};
    int map[MAXN][MAXN] = {{0}};
    int move[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    int r[MAXN*MAXN];
    int c[MAXN*MAXN];
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0; i<m; i++){
        scanf("%d%d", &r[i], &c[i]);
        map[r[i]][c[i]] = (i + 1) * 10000;
    }
    int valid = 1, count = m;
    while(valid){
        valid = 0;
        for(int i = 0; i < m; i++){
            int idx = nextMove(r[i], c[i], n, map);
            if(idx != -1){
                valid = 1;
                stepCount[i] ++;
                r[i] += move[idx][0], c[i] += move[idx][1];
                map[r[i]][c[i]] = (i + 1) * 10000 + stepCount[i];
            }//move
            #ifdef debug
            for(int ri = 0; ri < n; ri++){
                for(int ci = 0; ci < n; ci++){
                    printf("%5d%c", map[ri][ci], " \n"[ci == n-1]);
                }
            }
            printf("\n");
            #endif
        }//knights
    }//valid
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d%c", map[i][j], " \n"[j == n-1]);
        }
    }
    return 0;
}