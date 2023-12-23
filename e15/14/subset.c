#include "subset.h"
#include<stdio.h>
int sub(int numbers[], int idx, int sum, int pick, int n, int K, int S){
    // printf("idx = %d, sum = %d, pick = %d\n", idx, sum, pick);
    if(sum > K || pick > S || idx == n){
        // printf("\n");
        return((idx == n) && (sum == K) && (pick == S));
    }
    return sub(numbers, idx + 1, sum + numbers[idx], pick + 1, n, K, S) || \
    sub(numbers, idx + 1, sum, pick, n, K, S);
}
int subset(int numbers[], int n, int K, int S){
    return (sub(numbers, 0, 0, 0, n, K, S));
}