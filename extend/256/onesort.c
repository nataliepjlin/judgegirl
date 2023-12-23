#include<stdio.h>
#include<stdint.h>
#define MAX 1000
int counter(uint64_t n){
    int c = 0;
    while(n){
        c += (n % 2);
        n /= 2;
    }
    return c;
}
void swapUint(uint64_t *a, uint64_t *b){
    uint64_t tmp = *a;
    *a = *b;
    *b = tmp;
}
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void bs(uint64_t nums[], int counts[], int idx){
    for(int i = 0; i < idx; i++){
        for(int j = 0; j < idx - i - 1; j++){
            if(counts[j] > counts[j + 1]
            || (counts[j] == counts[j + 1] && nums[j] > nums[j + 1])){
                swap(&counts[j], &counts[j + 1]);
                swapUint(&nums[j], &nums[j + 1]);
            }
        }
    }
}
int main(){
    uint64_t nums[MAX];
    int counts[MAX] = {0};
    int idx = 0;
    while(scanf("%lu", &nums[idx]) != EOF){
        counts[idx] = counter(nums[idx]);
        idx++;
    }
    bs(nums, counts, idx);
    for(int i = 0; i < idx; i++){
        printf("%lu\n", nums[i]);
    }
}