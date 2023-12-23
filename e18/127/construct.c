#include<stdlib.h>
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
    int **D = (int **) malloc(sizeof(int *) * (N * N));
    for(int i = 0; i < N * N; i++){
        D[A[i / N][i % N]] = & A[i / N][i % N];
    }
    for(int i = 0; i < N * N; i++){
        B[i / N][i % N] = D[(A[i / N][i % N] + 1) % (N * N)];
    }
}