#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#define N 16384
// #define debug
int cmp(const void *a, const void *b){
    return(*(int *)a - *(int *)b);
}
uint64_t leftTorque(int l, int leftbound, int arr[]){
    #ifdef debug
    printf("l = %d, leftbound = %d, ", l, leftbound);
    #endif
    uint64_t t = 0;
    int d = 1;
    for(int i = l; i >= leftbound; i--, d++){
        t += arr[i] * d;
    }
    #ifdef debug
    printf("t = %lu\n", t);
    #endif
    return t;
}
uint64_t rightTorque(int r, int rightbound, int arr[]){
    #ifdef debug
    printf("r = %d, rightbound = %d, ", r, rightbound);
    #endif
    uint64_t t = 0;
    int d = 1;
    for(int i = r; i < rightbound; i++, d++){
        t += arr[i] * d;
    }
    #ifdef debug
    printf("t = %lu\n", t);
    #endif
    return t;
}
void solve(int arr[], int ans[], int *a,
int leftbound, int rightbound){
    #ifdef debug
    printf("leftbound = %d, rightbound = %d\n", leftbound, rightbound);
    #endif
    if(leftbound + 2 >= rightbound){//no more than two elements
        #ifdef debug
        printf("invalid\n\n");
        #endif
        return;
    }
    for(int i = leftbound; i < rightbound; i++){
        int l = i - 1, r = i + 1;
        uint64_t lt = leftTorque(l, leftbound, arr), rt = rightTorque(r, rightbound, arr);
        if(lt == rt){
            solve(arr, ans, a, leftbound, i);
            ans[*a] = i;
            #ifdef debug
            printf("ans[%d] = %d\n\n", *a, ans[*a]);
            #endif
            *a += 1;
            solve(arr, ans, a, i + 1, rightbound);
        }
    }
}
int main(){
    int n, arr[N];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int ans[N], a = 0;
    solve(arr, ans, &a, 0, n);
    // qsort(ans, a, sizeof(int), cmp);
    for(int i = 0; i < a; i++){
        printf("%d\n", ans[i]);
    }
}