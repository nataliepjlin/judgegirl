#include<stdio.h>
int main(){
    int row, col, matrix[600][600];
    scanf("%d%d", &row, &col);

    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            scanf("%d", &matrix[r][c]);
        }
    }

    int top = 0, right = col;
    int ope, k;
    while(scanf("%d%d", &ope, &k) == 2){
        if(ope == 1){
            for(int r = k; r < 2 * k; r++){
                // printf("r = %d, 2 * k - r - 1 = %d\n", r, 2 * k - r - 1);
                // printf("r + top = %d, 2 * k - r + top - 1 = %d\n", r + top, 2 * k - r + top - 1);
                for(int c = 0; c < right; c++){
                    matrix[r + top][c] += matrix[(2 * k - 1) - r + top][c];
                }
            }
            top += k;
        }
        else if(ope == 2){
            for(int c = right - k; c < right; c ++){
                for(int r = top; r < row; r++){
                    matrix[r][(2 * right - 2 * k - 1) - (c)] += matrix[r][c];
                }
            }
            right -= k;
        }
        else if(ope == 3){
            int count = 0;
            for(int r = top; r < k + top; r++){
                int midr = r, midc = right - k + count;
                // printf("\nmidr = %d, midc = %d\n", midr, midc);
                for(int c = midc + 1; c < right; c ++){
                    // printf("r = %d, c = %d\n", r, c);
                    int dr = c - midc;
                    // printf("original matrix[%d][%d] = %d\n", midr + dr, midc, matrix[midr + dr][midc]);
                    // printf("original matrix[%d][%d] = %d\n", r, c, matrix[r][c]);
                    matrix[midr + dr][midc] += matrix[r][c];
                    matrix[r][c] = 0;
                    
                }
                count ++;
            }
        }

        // printf("top = %d, bottom = %d, left = 0, right = %d\n", top, row, right);
    }

    for(int r = top; r < row; r++){
        for(int c = 0; c < right; c++){
            printf("%d%c", matrix[r][c], " \n"[c == right - 1]);
        }
    }
    
    return 0;
}
