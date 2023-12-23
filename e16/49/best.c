#include<stdio.h>
void matrix_multiplication(int N, int** ptrA, int M, int** ptrB, int S, int *result){
    for(int i = 0; i < S * S; i++){
        result[i] = 0;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            // printf("ptrA[2][%d] = %d, ptrB[1][%d] = %d\n", i, ptrA[2][i], j, ptrB[1][j]);
            if(ptrA[2][i] == ptrB[1][j]){//col1 == row2
                result[ptrA[1][i] * S + ptrB[2][j]] += ptrA[0][i] * ptrB[0][j];
                //row1, col2
            }
        }
    }
}