#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<limits.h>
#define N 25
#define LEN 55
// #define debug
void decomp(uint32_t *set, char *str, int len, int *cost){
    /*
    zyxwvutsrqponmlkjihgfedcba
               100010000000010
    */
    for(int i = 0; i < len; i++){
        *set |= (uint32_t)1 << (str[i] - 'a');
        *cost += (str[i] - 'a' + 1);
    }
}
int win(uint32_t nowpick){
    uint32_t checker = 0x3ffffff;
    return(nowpick == checker);
}
int getMin(int a, int b){
    return a * (a < b) + b * (a >= b);
}
void solve(uint32_t sets[], int n, int costs[], int idx,
int cost, int *mincost, uint32_t nowpick){
    if(win(nowpick)){
        *mincost = getMin(*mincost, cost);
        return;
    }
    if(idx >= n || cost > *mincost) 
        return;

    solve(sets, n, costs, idx + 1, cost + costs[idx], mincost, nowpick | sets[idx]);
    solve(sets, n, costs, idx + 1, cost, mincost, nowpick);
}
int main(){
    int n;
    while(scanf("%d", &n) == 1){
        uint32_t sets[N] = {0};
        int costs[N] = {0};
        char tmp[LEN];
        for(int i = 0; i < n; i++){
            scanf("%s", tmp);
            int len = strlen(tmp);
            decomp(&sets[i], tmp, len, &costs[i]);
        }
        int mincost = INT_MAX;
        uint32_t nowpick = 0;
        solve(sets, n, costs, 0, 0, &mincost, nowpick);
        printf("%d\n", mincost);
    }
}