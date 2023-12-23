#include <stdio.h>
#include <stdlib.h>
//#include "split.h"
 
void split(int A[], int *a[], int *head[], int k){
    int visit[100000] = {};
    int num = 0;
    while(a[num] != NULL) num++;
    num++;
    int **first;
    for(int i = 0; i < k; i++){
        first = &head[i];
        for(int j = 0; j < num; j++){
            if(!visit[j] && A[j] % k == i){ 
                *first = &A[j];
                first = &a[j];
                visit[j] = 1;
            }
        }
        *first = NULL;
    }
}