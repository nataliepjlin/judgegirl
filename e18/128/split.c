#include<stdio.h>
#define MAXK 100000
// #define debug
void split(int A[], int *a[], int *head[], int k){
    int len = 0;
    int prevs[MAXK] = {0};
    for(int i = 0; a[i] != NULL; i++, len++){
        a[i] = NULL;
    }
    len++;
    #ifdef debug
    printf("len = %d\n", len);
    #endif
    for(int i = 0; i < len; i++){
        int mod = A[i] % k;
        if(head[mod] == NULL){
            head[mod] = &A[i];
            prevs[mod] = i;
        }
        else{
            a[prevs[mod]] = &A[i];
            prevs[mod] = i;
        }
    }
}