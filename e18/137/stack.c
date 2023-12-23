#include<stdio.h>
#define N 201
#define MAX 1001
typedef struct{
    int w, h;
}PAPER;
typedef struct{
    int layer, sum;
}SOL;
int canPlace(PAPER top, PAPER btm){
    return(top.w <= btm.w && top.h <= btm.h
    || top.h <= btm.w && top.w <= btm.h);
}
SOL cmpSol(SOL a, SOL b){
    return(a.layer > b.layer
    || a.layer == b.layer && a.sum > b.sum)? a : b;
}
SOL solve(int idx, PAPER papers[], int n, PAPER prev, SOL nowsol){
    if(idx >= n)
        return nowsol;
    if(canPlace(papers[idx], prev)){
        SOL placed = {nowsol.layer + 1, nowsol.sum + idx};
        return cmpSol(solve(idx + 1, papers, n, papers[idx], placed),
        solve(idx + 1, papers, n, prev, nowsol));
    }
    return solve(idx + 1, papers, n, prev, nowsol);
}
int main(){
    int n;
    scanf("%d", &n);
    PAPER papers[N];
    for(int i = 0; i < n; i++){
        scanf("%d%d", &papers[i].w, &papers[i].h);
    }
    PAPER btm = {MAX, MAX};
    SOL initSol = {0, 0};
    SOL sol = solve(0, papers, n, btm, initSol);
    printf("%d %d\n", sol.layer, sol.sum);
}