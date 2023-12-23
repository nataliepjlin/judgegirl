#include<stdio.h>
#include<stdint.h>
#define N 64
#define M 36
typedef struct SET{
    int p1, p2;
}SET;
void solve(int n, int idx, int m, SET sets[], uint64_t f[], uint64_t selection, int nowcnt, uint64_t *ans, int *maxcnt){
    #ifdef debug
    printf("idx = %d/%d\n", idx, m);
    #endif
    if(nowcnt + m - idx <= *maxcnt){
        #ifdef debug
        printf("*maxcnt = %d, cut\n", *maxcnt);
        #endif
        return;
    }
    if(idx >= m){
        #ifdef debug
        printf("idx == m\n");
        #endif
        *maxcnt = nowcnt;
        *ans = selection;
        return;
    }
    int invalid = 0;
    for(int i = 0; i < n && !invalid; i++){
        invalid = ((f[i] & (uint64_t)1 << sets[idx].p1)
        && (f[i] & (uint64_t)1 << sets[idx].p2));
    }
    if(!invalid){
        #ifdef debug
        printf("try %dth set, (%d, %d)\n", idx, sets[idx].p1, sets[idx].p2);
        #endif
        f[sets[idx].p1] |= (uint64_t)1 << sets[idx].p2;
        f[sets[idx].p2] |= (uint64_t)1 << sets[idx].p1;
        solve(n, idx + 1, m, sets, f, selection | (uint64_t)1 << idx, nowcnt + 1, ans, maxcnt);
        f[sets[idx].p1] ^= (uint64_t)1 << sets[idx].p2;
        f[sets[idx].p2] ^= (uint64_t)1 << sets[idx].p1;
        #ifdef debug
        printf("unselect\n");
        #endif
    }
    solve(n, idx + 1, m, sets, f, selection, nowcnt, ans, maxcnt);
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    SET sets[M];
    for(int i = 0; i < m; i++){
        scanf("%d%d", &sets[i].p1, &sets[i].p2);
    }
    uint64_t f[N] = {0}; 
    int maxcnt = 0; uint64_t ans = 0;
    uint64_t selection = 0;
    solve(n, 0, m, sets, f, selection, 0, &ans, &maxcnt);
    for(int i = 0; i < m; i++){
        ((ans & 1) && (printf("%d %d\n", sets[i].p1, sets[i].p2)));
        ans >>= 1;
    }
}