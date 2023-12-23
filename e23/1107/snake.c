#include<stdio.h>
#include<string.h>
#define SIZE 55
#define MAXS 505
// #define debug
int oob(int r, int c, int n){
    return (r < 0 || c < 0 || r > n - 1 || c > n - 1);
}
void getHead(char map[SIZE][SIZE], int n, int *r, int *c){
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == '0') continue;
            int count = (!oob(i + dr[0], j + dc[0], n) && map[i + dr[0]][j + dc[0]] != '0') + \
                        (!oob(i + dr[1], j + dc[1], n) && map[i + dr[1]][j + dc[1]] != '0') + \
                        (!oob(i + dr[2], j + dc[2], n) && map[i + dr[2]][j + dc[2]] != '0') + \
                        (!oob(i + dr[3], j + dc[3], n) && map[i + dr[3]][j + dc[3]] != '0');
            if(count == 1 && (*r == -1 || map[i][j] < map[*r][*c])){
                *r = i;
                *c = j;
                #ifdef debug
                printf("now hr = %d, hc = %d\n", *r, *c);
                #endif
            }
        }
    }
}
int main(){
    char map[SIZE][SIZE];
    int n;
    scanf("%d", &n);
    getchar();
    int len = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%c", &map[i][j]);
            len += (map[i][j] != '0');
        }
        getchar();
    }
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    int r = -1, c = -1;
    getHead(map, n, &r, &c);
    char snake[MAXS] = {0};
    for(int i = 0; i < len; i++){
        snake[i] = map[r][c];
        #ifdef debug
        printf("now snake = %s\n", snake);
        #endif
        map[r][c] = '0';
        int found = 0;
        for(int d = 0; d < 4 && !found; d++){
            if(!oob(r + dr[d], c + dc[d], n) 
            && map[r + dr[d]][c + dc[d]] != '0'){
                r += dr[d];
                c += dc[d];
                found = 1;
            }
        }
    }
    printf("%s\n", snake);
}