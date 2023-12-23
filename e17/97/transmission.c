#include<stdio.h>
#include<stdint.h>
#define MAXSIZE 1048576
#define lld long long int
// #define debug
void transmission(long long int belt[],int N,int T){
    int round = T / 64;
    if(round > 0){
        lld tmp[N];
        for(int i = 0; i < N; i++){
            tmp[(i - round + N) % N] = belt[i];
        }
        for(int i = 0; i < N; i++){
            belt[i] = tmp[i];
        }
    }
    int remain = T % 64;
    #ifdef debug
    printf("remain = %d\n", remain);
    #endif
    if(remain){
        uint64_t now;
        uint64_t tmp;
        uint64_t n_1th = belt[N - 1], prev = n_1th >> (64 - remain);
        n_1th <<= remain;
        for(int i = N - 2; i >= 0; i--){
            now = tmp = belt[i];
            now >>= (64 - remain);
            tmp <<= remain;
            tmp |= prev;
            belt[i] = tmp;
            prev = now;
        }
        n_1th |= prev;
        belt[N - 1] = n_1th;
    }
}