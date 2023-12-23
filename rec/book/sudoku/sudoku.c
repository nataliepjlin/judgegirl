#include<stdio.h>
#define SUB 3
#define BLOCK 9
#define CELLS (BLOCK * BLOCK)
int placeNum(int n, int sudoku[BLOCK][BLOCK]){
    if(n == CELLS){
        for(int i = 0; i < BLOCK; i++){
            for(int j = 0; j < BLOCK; j++){
                printf("%d%c", sudoku[i][j], " \n"[j == BLOCK - 1]);
            }
        }
        return 1;
    }
    int r = n / BLOCK, c = n % BLOCK;
    if(sudoku[r][c])
        return placeNum(n + 1, sudoku);
    for(int try = 1; try <= BLOCK; try++){
        int conflict = 0;
        for(int i = 0; i < BLOCK && !conflict; i++){
            conflict = ((sudoku[r][i] == try && c != i)
                    || (sudoku[i][c] == try && r != i));
        }//check same row or same col's conflict
        if(!conflict){
            int subr = r / SUB, subc = c / SUB;
            for(int i = 0; i < SUB && !conflict; i++){
                for(int j = 0; j < SUB && !conflict; j++){
                    conflict = (sudoku[subr * SUB + i][subc * SUB + j] == try);
                }
            }//check sub
            if(!conflict){
                sudoku[r][c] = try;
                if(placeNum(n + 1, sudoku))
                    return 1;
            }
        }
    }//try
    sudoku[r][c] = 0;
    return 0;
}
int main(){
    int sudoku[BLOCK][BLOCK];
    for(int i = 0; i < BLOCK; i++){
        for(int j = 0; j < BLOCK; j++){
            scanf("%d", &sudoku[i][j]);
        }
    }
    placeNum(0, sudoku);
    return 0;
}