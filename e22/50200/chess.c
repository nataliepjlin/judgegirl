#include<stdio.h>
void printArr(int board[500][500], int row, int col){

    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            (c == 0) ? printf("%d", board[r][c]) : printf(" %d", board[r][c]);
        }
        if(r < row - 1) printf("\n");
    }

}
void up(int r, int c, int board[500][500]){
    for(int ri = r - 1; ri >= 0; ri--){
        if(board[ri][c] == 0) board[ri][c] = 1;
        else break;
    }
}
void down(int r, int c, int row, int board[500][500]){
    for(int ri = r + 1; ri < row; ri++){
        if(board[ri][c] == 0) board[ri][c] = 1;
        else break;
    }
}
void left(int r, int c, int board[500][500]){
    for(int ci = c - 1; ci >= 0; ci--){
        if(board[r][ci] == 0) board[r][ci] = 1;
        else break;
    }
}
void right(int r, int c, int col, int board[500][500]){
    for(int ci = c + 1; ci < col; ci++){
        if(board[r][ci] == 0) board[r][ci] = 1;
        else break;
    }
}
void d1u(int r, int c, int board[500][500]){
    int ri = r - 1; int ci = c - 1;
    while(ri >= 0 && ci >= 0 && board[ri][ci] == 0){
        board[ri][ci] = 1;
        ri --;
        ci --;
    }
}
void d1d(int r, int c, int row, int col, int board[500][500]){
    int ri = r + 1, ci = c + 1;
    while(ri <= row - 1 && ci <= col - 1 && board[ri][ci] == 0){
        board[ri][ci] = 1;
        ri ++;
        ci ++;
    }
}
void d2u(int r, int c, int col, int board[500][500]){
    int ri = r - 1, ci = c + 1;
    while(ri >= 0 && ci <= col - 1 && board[ri][ci] == 0){
        board[ri][ci] = 1;
        ri --;
        ci ++;
    }
}
void d2d(int r, int c, int row, int board[500][500]){
    int ri = r + 1, ci = c - 1;
    while(ri <= row - 1  && ci >= 0 && board[ri][ci] == 0){
        board[ri][ci] = 1;
        ri ++;
        ci --;
    }
}
int main(){
    int row, col;
    int board[500][500] = {{0}};
    scanf("%d%d", &row, &col);

    int type, c, r;
    while(scanf("%d%d%d", &type, &c, &r) == 3){
        // printf("type = %d, r = %d, c = %d\n", type, r, c);
        if(type == 0){
            board[r][c] = 1;
        }
        else if(type == 1){
            board[r][c] = 1;
            up(r, c, board);
            down(r, c, row, board);
            left(r, c, board);
            right(r, c, col, board);
            d1u(r, c, board);
            d1d(r, c, row, col, board);
            d2u(r, c, col, board);
            d2d(r, c, row, board);
        }
        else if(type == 2){
            board[r][c] = 1;
            d1u(r, c, board);
            d1d(r, c, row, col, board);
            d2u(r, c, col, board);
            d2d(r, c, row, board);
        }
        else if(type == 3){
            board[r][c] = 1;
            up(r, c, board);
            down(r, c, row, board);
            left(r, c, board);
            right(r, c, col, board);
        }
    }
    printArr(board, row, col);
    return 0;
}