#include <stdlib.h>
int *D[1024 * 1024];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
    for(int i = 0; i < N * N; i++){
        D[i] = (int*) malloc(sizeof(int));
    }
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            D[A[r][c]] = &A[r][c];
        }
    }
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            B[r][c] = D[(A[r][c] + 1) % (N * N)];
        }
    }
}