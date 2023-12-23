#include<stdio.h>
#include<string.h>
// #define debug
int findSmall(int A[], int B[], int sizeA, int sizeB, int *a[], int *b[]){
    for(int i = 0; i < sizeA; i++){
        a[i] = NULL;
    }
    for(int i = 0; i < sizeB; i++){
        b[i] = NULL;
    }
    int i = (A[0] < B[0]), j = (A[0] >= B[0]);
    int *tmp[sizeA + sizeB], idx = 0;
    memset(tmp, 0, sizeof(tmp));
    #ifdef debug
    printf("i = %d, j = %d\n", i, j);
    #endif
    int idxa = 0, idxb = 0;
    while(i < sizeA  && j < sizeB){
        if(A[i] < B[j]){
           tmp[idx] = &A[i];
           idx ++;
           i++;
        }
        else{//B[j] < A[i]
            tmp[idx] = &B[j];
            idx ++;
            j++;
        }
    }
    if(i == sizeA){
        for(int k = j; k < sizeB; k++){
            tmp[idx] = &B[j];
            idx ++;
            j++;
        }
    }
    else if(j == sizeB){
        for(int k = i; k < sizeA; k++){
           tmp[idx] = &A[i];
           idx ++;
           i++;
        }
    }
    #ifdef debug
    printf("idx = %d\n", idx);
    #endif
    i = 0, j = 0;
    for(int t = 0; t < idx; t++){
        if(j == sizeB 
        ||(i < sizeA && A[i] < B[j])){
            a[i] = tmp[t];
            #ifdef debug
            printf("*a[%d] = %d\n", i, *a[i]);
            #endif
            i ++;
        }
        else{
            b[j] = tmp[t];
            #ifdef debug
            printf("*b[%d] = %d\n", j, *b[j]);
            #endif
            j ++;
        }
    }
}
void merge(int A[], int B[], int* a[], int* b[]){
    int sizeA = 0, sizeB = 0;
    while(a[sizeA] != NULL) sizeA ++;
    while(b[sizeB] != NULL) sizeB ++;
    sizeA ++, sizeB ++;
    #ifdef debug
    printf("sizeA = %d, sizeB = %d\n", sizeA, sizeB);
    #endif
    findSmall(A, B, sizeA, sizeB, a, b);
}
