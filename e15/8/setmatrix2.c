#include<stdio.h>
// #define debug
void processSetMatrix(int ***ptr){
    for(int i = 0; ptr[i]; i++){
        for(int j = 0; ptr[i][j]; j++){
            for(int k = 0; ptr[i][j][k]; k++){
                #ifdef debug
                printf("ptr[%d][%d][%d] = %d\n", i, j, k, ptr[i][j][k]);
                #endif
                if(!(!i && !j && !k)) printf(" ");
                printf("%d", ptr[i][j][k]);// == *(*(*(ptr + i) + j) + k)
            }
        }
    }
    printf("\n");
}