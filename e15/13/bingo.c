#include<stdint.h>
#include<stdio.h>
// #define debug
#define N 8
int bingo(const unsigned long long int *board, int *rowColumn){
    uint64_t rowchecker = 0xff00000000000000;
    for(int i = 0; i < N; i++){
        #ifdef debug
        printf("now rowchecker = %llx\n", rowchecker);
        #endif
        if(!((*board & rowchecker) ^ rowchecker)){
            *rowColumn = i;
            return 1;
        }
        rowchecker >>= 8;
    }
    uint64_t colchecker = 0x8080808080808080;
    for(int i = 0; i < N; i++){
        #ifdef debug
        printf("now colchecker = %llx\n", colchecker);
        #endif
        if(!((*board & colchecker) ^ colchecker)){
            *rowColumn = i;
            return 2;
        }
        colchecker >>= 1;
    }
    uint64_t dia1 = 0x8040201008040201, dia2 = 0x0102040810204080;
    if(!((*board & dia1) ^ dia1)){
        *rowColumn = 0;
        return 3;
    }
    if(!((*board & dia2) ^ dia2)){
        *rowColumn = 1;
        return 3;
    }
    return 0;
}