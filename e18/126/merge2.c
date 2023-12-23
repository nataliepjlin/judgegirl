#include <stdio.h>
// #define debug
void merge(int A[], int B[], int* a[], int* b[]){
    int sizeA = 0, sizeB = 0;
    while(a[sizeA] != NULL) sizeA ++;
    sizeA ++;
    while(b[sizeB] != NULL) sizeB ++;
    sizeB ++;
    #ifdef debug
    printf("sizeA = %d, sizeB = %d\n", sizeA, sizeB);
    #endif
    int **now;
    int i = 0, j = 0;
    if(A[0] < B[0]){
        now = &a[0];//first ptr array that need to be filled
        i ++;
    }
    else{
        now = &b[0];
        j ++;
    }
    while(i < sizeA && j < sizeB){
        if(A[i] < B[j]){
            *now = &A[i];
            now = &a[i];
            i ++;
        }
        else{
            *now = &B[j];
            now = &b[j];
            j ++;
        }
    }
    if(i == sizeA){
        *now = &B[j];
    }
    else{
        *now = &A[i];
    }
}