#include<stdint.h>
#include<stdio.h>
#define N 8
void printMatrix(uint64_t *matrix){
    printf("%lu\n", *matrix);
    for(int i = 0; i < N * N; i++){
        printf("%ld", (*matrix >> i) & 1);
        ((i % N == N - 1) && printf("\n"));
    }
}
void rotateMatrix(uint64_t *matrix){
    uint64_t tmp = 0;
    int t = 0;
    for(int c = 0; c < N; c++){
        for(int r = N - 1; r >= 0; r--, t++){
            tmp |= ((*matrix >> (r * N + c)) & 1)<< t;
        }
    }
    *matrix = tmp;
}
void transposeMatrix(uint64_t *matrix){
    uint64_t tmp = 0;
    int t = 0;
    for(int c = 0; c < N; c++){
        for(int r = 0; r < N; r++, t++){
            tmp |= (((*matrix) >> (r * N + c)) & 1) << t; 
        }
    }
    *matrix = tmp;
}