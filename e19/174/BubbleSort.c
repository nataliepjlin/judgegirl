#include <stdint.h>
#include<stdio.h>
#include<inttypes.h>
#define debug
void BubbleSort(uint64_t input, uint64_t output[63]){
    for(int i = 0; i < 63; i++){
        for(int j = 0; j < 64 - i - 1; j++){
            if(((input >> (63 - j)) & 1) && !((input >> (63 - (j + 1))) & 1)){
                input ^= ((uint64_t)1 << (63 - j));
                input ^= ((uint64_t)1 << (63 - (j + 1)));
            }
        }
        output[i] = input;
    }
}