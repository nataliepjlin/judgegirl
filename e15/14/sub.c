#include "subset.h"
#include<stdio.h>
// #define debug
int subset(int numbers[], int n, int K, int S){
    if(n < S)
        return 0;
    if(n == 0 || K <= 0 || S <= 0){
        #ifdef debug
        printf("\n");
        #endif
        return (S == 0 && K == 0);
    }
    return  subset(numbers, n - 1, K, S) || subset(numbers, n - 1, K - numbers[n - 1], S - 1);
}