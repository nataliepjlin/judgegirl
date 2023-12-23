#include<stdio.h>
#define N 9
// #define debug
int det(int matrix[N][N], int size){
    for(int r = 0; r < size; r++){
        for(int c = 0; c < size; c++){
            printf("%d%c", matrix[r][c], " \n"[c == size - 1]);
        }
    }
    if(size == 2){
        int a = matrix[0][0], b = matrix[0][1], 
        c = matrix[1][0], d = matrix[1][1];
        printf("%d\n%d\n", d, c);
        int val = a * d - b * c;
        printf("determinant=%d\n", val);
        return val;
    }
    else{//size >= 3
        int sign = 1;
        int val = 0;
        for(int col = 0; col < size; col++){
            int head = matrix[0][col];
            int new[N][N];
            for(int r = 1; r < size; r++){
                for(int c = 0; c < size; c++){
                    new[r - 1][c - (c > col)] = matrix[r][c];
                }
            }
            val += sign * head * det(new, size - 1);
            sign *= (-1);
        }
        printf("determinant=%d\n", val);
        return val;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    int matrix[N][N] = {{0}};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    det(matrix, n);
}