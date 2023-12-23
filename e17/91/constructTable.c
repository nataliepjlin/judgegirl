#include<stdio.h>
int **first[100 + 1];
int *second[100 * 100 + 1];
int ***constructTable(int A[], int B[]){
    int ***ptr1 = first, **ptr2 = second;
    int *bptr = B;
    for(int i = 0; A[i]; i++){
        *ptr1 = ptr2;
        ptr1 ++;
        for(int j = 0; j < A[i]; j++){
            *ptr2 = bptr;
            ptr2 ++;
            while(*bptr) bptr ++;
            bptr ++;
        }
        *ptr2 = NULL;
        ptr2 ++;
    }
    *ptr1 = NULL;
    return first;
}