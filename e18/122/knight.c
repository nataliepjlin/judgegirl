#include<stdio.h>
// #define debug
#define MaxN 100
#define MaxM 10000
#define MaxP 8
int pCount(int r, int c, int board[MaxN][MaxN], int n){
    int p = (r >= 2 && c < n - 1 && !board[r - 2][c + 1]) +
            (r >= 1 && c < n - 2 && !board[r - 1][c + 2]) +
            (r < n - 1 && c < n - 2 && !board[r + 1][c + 2]) +
            (r + 2 < n && c + 1 < n && !board[r + 2][c + 1]) +
            (r <= n - 3 && c > 0 && !board[r + 2][c - 1]) + 
            (r < n - 1 && c > 1 && !board[r + 1][c - 2]) + 
            (r > 0 && c > 1 && !board[r - 1][c - 2]) + 
            (r > 1 && c > 0 && !board[r - 2][c - 1]);
    #ifdef debug
    // printf("check p from (%d, %d)\n", r, c);
    // printf("p = %d\n", p);
    #endif
    return p;
}
void chooseMove(int r, int c, int board[MaxN][MaxN], int n, int nextMove[2]){
    int min = MaxP;
    if(r >= 2 && c < n - 1 && !board[r - 2][c + 1]){
        if(pCount(r - 2, c + 1, board, n) < min){
            nextMove[0] = r - 2, nextMove[1] = c + 1;
            min = pCount(r - 2, c + 1, board, n);
        } 
    }
    if(r >= 1 && c < n - 2 && !board[r - 1][c + 2]){
        if(pCount(r - 1, c + 2, board, n) < min){
            nextMove[0] = r - 1, nextMove[1] = c + 2;
            min = pCount(r - 1, c + 2, board, n);
        } 
    }
    if(r < n - 1 && c < n - 2 && !board[r + 1][c + 2]){
        if(pCount(r + 1, c + 2, board, n) < min){
            nextMove[0] = r + 1, nextMove[1] = c + 2;
            min = pCount(r + 1, c + 2, board, n);
        } 
    }
    if(r + 2 < n && c + 1 < n && !board[r + 2][c + 1]){
        if(pCount(r + 2, c + 1, board, n) < min){
            nextMove[0] = r + 2, nextMove[1] = c + 1;
            min = pCount(r + 2, c + 1, board, n);
        } 
    } 
    if(r <= n - 3 && c > 0 && !board[r + 2][c - 1]){
        if(pCount(r + 2, c - 1, board, n) < min){
            nextMove[0] = r + 2, nextMove[1] = c - 1;
            min = pCount(r + 2, c - 1, board, n);
        } 
    }//5
    if(r < n - 1 && c > 1 && !board[r + 1][c - 2]){
        if(pCount(r + 1, c - 2, board, n) < min){
            nextMove[0] = r + 1, nextMove[1] = c - 2;
            min = pCount(r + 1, c - 2, board, n);
        } 
    }//6
    if(r > 0 && c > 1 && !board[r - 1][c - 2]){
        if(pCount(r - 1, c - 2, board, n) < min){
            nextMove[0] = r - 1, nextMove[1] = c - 2;
            min = pCount(r - 1, c - 2, board, n);
        } 
    }//7
    if(r > 1 && c > 0 && !board[r - 2][c - 1]){
        if(pCount(r - 2, c - 1, board, n) < min){
            nextMove[0] = r - 2, nextMove[1] = c - 1;
            min = pCount(r - 2, c - 1, board, n);
        } 
    }//8
}
int main(){
    int board[MaxN][MaxN] = {{0}};//10000×index+stepCount
    int position[MaxM][3];
    int n, m;
    scanf("%d%d", &n, &m);
    for(int k = 0; k < m; k++){
        scanf("%d%d", &position[k][0], &position[k][1]);
        position[k][2] = 0;//stepCount
        board[position[k][0]][position[k][1]] = 10000 * (k + 1);
    }

    int found = 1;
    while(found){
        found = 0;
        for(int k = 0; k < m; k++){
            int r = position[k][0], c = position[k][1];
            int nextMove[2] = {-1, - 1};
            #ifdef debug
            printf("k = %d, r = %d, c = %d\n", k, r, c);
            #endif
            chooseMove(r, c, board, n, nextMove);
            #ifdef debug
            printf("nextMove[0] = %d, nextMove[1] = %d\n", nextMove[0], nextMove[1]);
            #endif
            if(nextMove[0] != -1 && nextMove[1] != -1){
                found = 1;
                r = nextMove[0], c = nextMove[1];
                position[k][0] = r, position[k][1] = c; position[k][2] ++;
                board[r][c] = 10000 * (k + 1) + position[k][2];
            }
        }
    }

    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            printf("%d%c", board[r][c], " \n"[c == n - 1]);
        }
    }
    return 0;
}