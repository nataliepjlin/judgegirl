#include<stdio.h>
#define SIZE 50
// #define debug
void game_of_cell(int grid[SIZE][SIZE],int outcome[SIZE][SIZE],int N){
    int map[SIZE + 2][SIZE + 2];
    int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            map[i + 1][j + 1] = grid[i][j];
        }
    }//setting maps

    int changeStatus[3][9] = {
    {0, 0, 0, 2, 0, 0, 0, 0, 0},
    {1, 1, 2, 1, 1, 1, 1, 1, 1},
    {0, 0, 2, 2, 1, 1, 1, 1, 1}};
    for(int round = 0; round < N; round ++){
        int alive[SIZE + 2][SIZE + 2] = {{0}};
        for(int i = 1; i < SIZE + 1; i++){
            for(int j = 1; j < SIZE + 1; j++){
                alive[i][j] += map[i - 1][j - 1] / 2;
                alive[i][j] += map[i - 1][j] / 2;
                alive[i][j] += map[i - 1][j + 1] / 2;
                alive[i][j] += map[i][j - 1] / 2;
                alive[i][j] += map[i][j + 1] / 2;
                alive[i][j] += map[i + 1][j - 1] / 2;
                alive[i][j] += map[i + 1][j] / 2;
                alive[i][j] += map[i + 1][j + 1] / 2;
            }
        }
        for(int i = 1; i < SIZE + 1; i++){
            for(int j = 1; j < SIZE + 1; j++){
                outcome[i - 1][j - 1] = map[i][j] = changeStatus[map[i][j]][alive[i][j]];
            }
        }
    }//end of round
}
