#include<stdio.h>
int main(){
    int n;
    double A[16][16], X[16], Y[16];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%lf", &A[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        scanf("%lf", &Y[i]);
    }

    X[n - 1] = Y[n - 1] / A[n - 1][n - 1];
    // printf("%f\n", X[n - 1]);

    for(int i = n - 2; i >= 0; i--){
        double nume = Y[i];
        for(int j = i + 1; j < n; j ++){
            // printf("i = %d, j = %d\n", i, j);
            nume -= A[i][j] * X[j]; 
        }
        // printf("nume = %f\n", nume);
        X[i] = nume / A[i][i];
        // printf("X[%d] = %f\n", i, X[i]);
    }

    for(int i = 0; i < n; i++){
        printf("%f\n", X[i]);
    }
    return 0;

}