#include<stdio.h>
#include<stdint.h>
#define N 64
// #define debug
int max(int a, int b){
    return a * (a > b) + b * (a <= b);
}
void solve(int dons[], int idx, int n, uint64_t hate[], uint64_t blacklist, 
int nowdon, int *maxdon){
    if(idx >= n){
        *maxdon = max(*maxdon, nowdon);
        return;
    }

    if((blacklist & (uint64_t)1 << idx) == 0)
        solve(dons, idx + 1, n, hate, blacklist | hate[idx], nowdon + dons[idx], maxdon);
    
    solve(dons, idx + 1, n, hate, blacklist, nowdon, maxdon);
}
int main(){
    int n; scanf("%d", &n);
    int dons[N];
    for(int i = 0; i < n; i++){
        scanf("%d", &dons[i]);
    }
    uint64_t hate[N] = {0};
    uint64_t h;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%lu", &h);
            hate[i] |= (h << j);
        }
        #ifdef debug
        printf("hate[%d] = %lu\n", i, hate[i]);
        #endif
    }
    int maxdon = 0;
    solve(dons, 0, n, hate, (uint64_t)0, 0, &maxdon);
    printf("%d\n", maxdon);
}