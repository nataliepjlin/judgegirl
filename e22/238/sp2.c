#include<stdio.h>
int mult(int a[], int b[]){
    int ans = 0;
    int i = 1, j = 1;
    while(a[i] != -1 && b[j] != -1){
        if(a[i] < b[j]) i += 2;
        else if(a[i] > b[j]) j += 2;
        else{
            ans += a[i + 1] * b[j + 1];
            i += 2, j += 2;
        }
    }
    return ans;
}
void sparseMatrixMult(int** A, int** B){
    for(int i = 0; A[i] != NULL; i++){
        for(int j = 0; B[j] != NULL; j++){
            int ans = mult(A[i], B[j]);
            if(ans){
                printf("%d %d %d\n", A[i][0], B[j][0], ans);
            }
        }
    }
}