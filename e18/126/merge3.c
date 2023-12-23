#include <stdio.h>
// #define debug
void merge(int A[], int B[], int* a[], int* b[]){
    int sizeA = 0, sizeB = 0;
    while(a[sizeA] != NULL) sizeA++;
    sizeA++;
    while(b[sizeB] != NULL) sizeB++;
    sizeB++;
    #ifdef debug
    printf("sizeA = %d, sizeB = %d\n", sizeA, sizeB);
    #endif

    int **tofill;
    int i = 0, j = 0;
    if(A[0] < B[0]){
        tofill = &a[0];
        i++;
        #ifdef debug
        printf("1st tofill = a[0]\n");
        #endif
    }
    else{
        tofill = &b[0];
        j++;
    }
    while(i < sizeA && j < sizeB){
        #ifdef debug
        printf("A[%d] = %d, B[%d] = %d\n", i, A[i], j, B[j]);
        #endif
        if(A[i] < B[j]){
            *tofill = &A[i];
            tofill = &a[i];
            #ifdef debug
            printf("fill with A[%d]\n\n", i);
            printf("next tofill = a[%d]\n", i);
            #endif
            i++;
        }
        else{
            *tofill = &B[j];
            tofill = &b[j];
            #ifdef debug
            printf("fill with B[%d]\n\n", j);
            printf("next tofill = b[%d]\n", j);
            #endif
            j++;
        }
    }
    if(i == sizeA){
        *tofill = &B[j];
    }
    else{
        *tofill = &A[i];
    }
}