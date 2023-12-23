#include <stdio.h>
#include <string.h>
// #define debug
void fill_rectangle_neg(int *upper_left, int *bottom_right, int n_row, int n_col, int fill){
    int row = (bottom_right - upper_left) / n_col, col = (bottom_right - upper_left) % n_col;
    for(int r = 0; r <= row; r++){
        for(int c = 0; c <= col; c++){
            *(upper_left + (r * n_col) + c) = fill;
        }
    }
}
void fill_rectangle_pos(int *upper_right, int *bottom_left, int n_row, int n_col, int fill){
    // if(upper_right == bottom_left) *upper_right = fill;
    // else{
        int row = (bottom_left - upper_right) / n_col + 1, col = (row * n_col - (bottom_left - upper_right)) % n_col;
        row -= (col == 0 || (upper_right + (row * n_col) - col != bottom_left));//or the  
        //row1 ≤ row2 and col1 ≥ col2.
        #ifdef debug
        printf("row, col = %d, %d\n", row, col);
        #endif
        for(int r = 0; r <= row; r++){
            for(int c = 0; c <= col; c++){
                #ifdef debug
                printf("r, c = %d, %d\n", r, c);
                #endif
                *(upper_right + (r * n_col) - c) = fill;
            }
            #ifdef debug
            printf("\n");
            #endif
        }
        #ifdef debug
        printf("\n");
        #endif
    // }
}
