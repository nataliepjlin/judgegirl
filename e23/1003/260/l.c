#include<stdio.h>
#define MAXN 100
#define debug
int oob(int r, int c, int n){
    return (r < 0 || c < 0 || r > n - 1 || c > n - 1);
}
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void bs(int output[][4], int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m - i - 1; j++){
            if(output[j][0] > output[j + 1][0]){
                swap(&output[j][0], &output[j + 1][0]);
                swap(&output[j][1], &output[j + 1][1]);
                swap(&output[j][2], &output[j + 1][2]);
                swap(&output[j][3], &output[j + 1][3]);
            }
        }
    }
}
int main(){
    int map[MAXN][MAXN];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n * n; i++){
        scanf("%d", &map[i / n][i % n]);
    }
    int m;
    scanf("%d", &m);
    int output[m][4];
    int dr[] = {-1, -1, 1, 1};
    int dc[] = {1, -1, -1, 1};
    int r, c;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &r, &c);
        int dir = (!oob(r + dr[1], c, n) && !oob(r, c + dc[1], n) && map[r + dr[1]][c] && map[r][c + dc[1]]) * 1
        + (!oob(r + dr[2], c, n) && !oob(r, c + dc[2], n) && map[r + dr[2]][c] && map[r][c + dc[2]]) * 2
        + (!oob(r + dr[3], c, n) && !oob(r, c + dc[3], n) && map[r + dr[3]][c] && map[r][c + dc[3]]) * 3;
        output[i][0] = r * n + c;
        output[i][1] = dir;
        int h = 1, v = 1;
        int nowr = r, nowc = c;
        while(!oob(nowr + dr[dir], c, n) && map[nowr + dr[dir]][c]){
            v++;
            nowr += dr[dir];
        }
        while(!oob(r, nowc + dc[dir], n) && map[r][nowc + dc[dir]]){
            nowc += dc[dir];
            h++;
        }
        output[i][2] = v;
        output[i][3] = h;
    }
    bs(output, m, n);
    for(int i = 0; i < m; i++){
        printf("%d %d %d\n", output[i][1], output[i][2], output[i][3]);
    }
    return 0;
}