#include <stdio.h>                     
#define ull unsigned long long int
void printBlock(ull *block) {
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            printf("%llu", (*block) >> (i * 8 + j) & 1);
        }
        printf("\n");
    }
}
 
void initialize(ull *block, int row, int column, int size) {
    *block = (ull) 0;
    ull mask = 0;
    for(int i = 0; i < size; i++){
        mask |= (ull)1 << i;
    }
    // printf("mask = %lu\n", mask);
    for(int r = row; r < row + size; r++){
        *block |= (mask << ((r * 8) + column));
    }
} 
int moveLeft(ull *block) {
    if(*block & (ull)0b0000000100000001000000010000000100000001000000010000000100000001) return 0;
    else{
        (*block) >>= 1;
        return 1;
    }
}
 
int moveRight(ull *block) {
    if(*block & (ull)0b1000000010000000100000001000000010000000100000001000000010000000) return 0;
    else{
        (*block) <<= 1;
        return 1;
    }
}
int moveUp(ull *block) {
    if(*block & (ull)0x00000000000000FF) return 0;
    else{
        (*block) >>= 8;
        return 1;
    }
}
int moveDown(ull *block) {
    if(*block & (ull)0xFF00000000000000) return 0;
    else{
        (*block) <<= 8;
        return 1;
    }
}
