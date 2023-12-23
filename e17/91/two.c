#include<stdlib.h>
#include<stdio.h>
// #define debug
int ***constructTable(int A[], int B[]){
    int ***ptr;
    int level1Size = 0, level2Size = 0;
    for(level1Size; A[level1Size] != 0; level1Size++){
        level2Size += (A[level1Size] + 1);
    }
    int **lev1[level1Size + 1], *lev2[level2Size];
    for(int i = 0; i < level2Size; i++){
        lev2[i] = (int *)malloc(sizeof(int));
    }
    #ifdef debug
    printf("level1Size = %d\n", level1Size);
    #endif
    ptr = &lev1[0];
    lev1[level1Size] = NULL;
    lev1[0] = &lev2[0];
    int nextLev2 = A[0] + 1;
    for(int i = 1; i < level1Size; i++){
        lev1[i] = &lev2[nextLev2];
        lev2[nextLev2 - 1] = NULL;
        nextLev2 += (A[i] + 1);
    }
    lev2[0] = &B[0];
    int lv2Idx = 1;
    for(int i = 1; lv2Idx < level2Size - 1; i++){
        if(B[i] == 0){
            if(lev2[lv2Idx] == NULL)
                lv2Idx ++;
            lev2[lv2Idx] = &B[i + 1];
            lv2Idx ++;
        }
    }
    for(int i = 0; i < level1Size; i++){
        for(int j = 0; j < A[i]; j++){
            for(int k = 0; ptr[i][j][k] != 0; k++){
                printf("%d ", ptr[i][j][k]);
            }
        }
    }
    *ptr = NULL;
    return ptr;
}