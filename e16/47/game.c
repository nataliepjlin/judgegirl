#include<stdio.h>
#define SIZE 50
// #define debug
int oob(int r, int c){
    return (r < 0 || r > SIZE - 1 || c < 0 || c > SIZE - 1);
}
void game_of_cell(int grid[SIZE][SIZE],int outcome[SIZE][SIZE],int N){
    int now = 0, next = 1;
    int map[2][SIZE][SIZE];
    int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            map[now][i][j] = map[next][i][j] = grid[i][j];
        }
    }//setting maps
 
    int changeStatus[3][9] = {
    {0, 0, 0, 2, 0, 0, 0, 0, 0},
    {1, 1, 2, 1, 1, 1, 1, 1, 1},
    {0, 0, 2, 2, 1, 1, 1, 1, 1}};
    for(int round = 0; round < N; round ++){
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                int count = 0;
                count += (!oob(i + dr[0], j + dc[0]) && (map[now][i + dr[0]][j + dc[0]] == 2));
                count += (!oob(i + dr[1], j + dc[1]) && (map[now][i + dr[1]][j + dc[1]] == 2));
                count += (!oob(i + dr[2], j + dc[2]) && (map[now][i + dr[2]][j + dc[2]] == 2));
                count += (!oob(i + dr[3], j + dc[3]) && (map[now][i + dr[3]][j + dc[3]] == 2));
                count += (!oob(i + dr[4], j + dc[4]) && (map[now][i + dr[4]][j + dc[4]] == 2));
                count += (!oob(i + dr[5], j + dc[5]) && (map[now][i + dr[5]][j + dc[5]] == 2));
                count += (!oob(i + dr[6], j + dc[6]) && (map[now][i + dr[6]][j + dc[6]] == 2));
                count += (!oob(i + dr[7], j + dc[7]) && (map[now][i + dr[7]][j + dc[7]] == 2));
            
                #ifdef debug
                printf("(%d, %d) = %d, count = %d\n", i, j, map[now][i][j], count);
                #endif
                outcome[i][j] = map[next][i][j] = changeStatus[map[now][i][j]][count];
                #ifdef debug
                printf("set map[next][i][j] to %d\n", map[next][i][j]);
                #endif
            } 
        }
        now ^= 1, next ^= 1;
    }//end of round
}