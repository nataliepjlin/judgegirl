#include<stdio.h>
# define ROW 3
# define COL 5
// #define debug
typedef int A[ROW][COL];
typedef int B[COL][ROW];
typedef int C[ROW][ROW];
 
void multiplyMatrix(A **arrayA, B **arrayB, C **arrayC) {
    int size = 0;
    while(arrayA[size] != NULL) size++;
    #ifdef debug
    printf("size = %d\n", size);
    #endif
    for(int s = 0; s < size; s++){
        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < ROW; j++){
                // printf("%d%c", *(*(*(arrayA[s]) + i)  + j), " \n"[j == COL - 1]);
                *(*(*(arrayC[s]) + i)  + j) = 0;
                for(int k = 0; k < COL; k++){
                    *(*(*(arrayC[s]) + i)  + j) += (*(*(*(arrayA[s]) + i)  + k)) * (*(*(*(arrayB[s]) + k)  + j));
                }
            }
        }
    }
}
