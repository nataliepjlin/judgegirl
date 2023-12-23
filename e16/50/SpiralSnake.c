#ifndef SPIRALSNAKE_H_INCLUDED
#define SPIRALSNAKE_H_INCLUDED
#include<stdio.h>
// #define debug
void SpiralSnake(int N, int *snake, int *result){
    int dr[4] = {0, -1, 0, 1};
    int dc[4] = {-1, 0, 1, 0};
    int dir = 0;
    int r = (N / 2), c = (N / 2);
    int count = 0;
    for(int t = 1; c >= 0; t++){
        for(int i = 0; i < 2 && c >= 0; i++){
            for(int j = 0; j < t && c >= 0; j ++){
                #ifdef debug
                printf("r, c = %d, %d; snake[%d] = %d\n", r, c, count, snake[count]);
                #endif
                result[r * N + c] = snake[count];
                r += dr[dir];
                c += dc[dir];
                count ++;
            }
            dir = (dir + 1) % 4;
        }
    }
    
}
#endif