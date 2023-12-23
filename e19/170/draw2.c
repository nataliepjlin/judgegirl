#include<stdio.h>
// #define debug
void fill_rectangle_neg(int *upper_left, int *bottom_right, int n_row, int n_col, int fill){
    int diff = bottom_right - upper_left;
    int row = diff / n_col, col = diff % n_col;
    for(int i = 0; i <= row; i++){
        for(int j = 0; j <= col; j++){
            upper_left[i * n_col + j] = fill;
        }
    }
}
void fill_rectangle_pos(int *upper_right, int *bottom_left, int n_row, int n_col, int fill){
    int diff = (bottom_left - upper_right);
    #ifdef debug
    printf("diff = %d\n", diff);
    #endif
    diff = ((diff % n_col) - 2 * n_col) % n_col;
    #ifdef debug
    printf("diff = %d\n", diff);
    #endif
    fill_rectangle_neg(upper_right + diff, bottom_left - diff, n_row, n_col, fill);
}