#include<stdio.h>
#define N 64
// #define debug
int hasall(int select[], int s, int m, int f[][2]){
    int have[N] = {0};
    for(int i = 0; i < s; i++)
        have[select[i]] = 1;
    for(int i = 0; i < m; i++){
         if(!have[f[i][0]] && !have[f[i][1]]) 
            return 0;
    }
    return 1;
}
void solve(int select[], int s, int idx, int n, int *minpick, int ans[], 
int m, int f[][2]){
    #ifdef debug
    printf("idx = %d\n", idx);
    #endif
    if(s >= *minpick){
        #ifdef debug
        printf("s = %d > minpick = %d\n", s, *minpick);
        #endif
        return;
    }
    if(idx == n){
        if(hasall(select, s, m, f)){
            *minpick = s;
            for(int i = 0; i < s; i++)
                ans[i] = select[i];
        }
        return;
    }
    select[s] = idx;
    solve(select, s + 1, idx + 1, n, minpick, ans, m, f);
 
    select[s] = 0;
    solve(select, s, idx + 1, n, minpick, ans, m, f);
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int f[m][2];
    for(int i = 0; i < m; i++){
        scanf("%d%d", &f[i][0], &f[i][1]);
    }
    int select[N], ans[N] = {0};
    int minpick = N * 2;
    solve(select, 0, 0, n, &minpick, ans, m, f);
    for(int i = 0; i < minpick; i++)
        printf("%d\n", ans[i]);
}