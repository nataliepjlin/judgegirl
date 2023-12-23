#include<stdio.h>
int **firstLev[100];
int *secondLev[100 * 100];
int ***constructTable(int A[], int B[]){
    int ***ptr1 = firstLev, **ptr2 = secondLev, *bptr = B;
    for(int i = 0; A[i] != 0; i++){
        *ptr1 = ptr2;
        ptr1 ++;
        for(int j = 0; j < A[i]; j++){
            *ptr2 = bptr;
            ptr2 ++;
            while(*bptr){
                bptr++;
            }
            bptr ++;
        }
        *ptr2 = NULL;
        ptr2 ++;
    }
    *ptr1 = NULL;
    return firstLev;
}