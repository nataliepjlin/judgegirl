#include<stdio.h>
typedef struct{
    int w, h;
}PAPER;
typedef struct{
    int layer;
    int sum;
}SOL;
int onTop(PAPER t, PAPER b){
    return((t.w <= b.w && t.h <= b.h)
    || (t.h <= b.w && t.w <= b.h));
}
SOL betterSol(SOL a, SOL b){
    return(a.layer > b.layer
    || (a.layer == b.layer && a.sum > b.sum)) ? a : b;
}
SOL getSol(int idx, int n, PAPER prevTop, PAPER papers[], SOL sol){
    if(idx >= n)
        return sol;
    if(onTop(papers[idx], prevTop)){
        SOL placed = (SOL){sol.layer + 1, sol.sum + idx};
        return betterSol(getSol(idx + 1, n, papers[idx], papers, placed),
        getSol(idx + 1, n, prevTop, papers, sol));
    }
    else{
        return getSol(idx + 1, n, prevTop, papers, sol);
    }
}
void printSol(SOL sol){
    printf("%d %d\n", sol.layer, sol.sum);
}
#define BOTTOM 1001
#define N 201
int main(){
    int n;
    scanf("%d", &n);
    PAPER papers[N];
    for(int i = 0; i < n; i++){
        scanf("%d%d", &papers[i].w, &papers[i].h);
    }
    PAPER bottom = {BOTTOM, BOTTOM};
    SOL initSol = {0, 0};
    SOL sol = getSol(0, n, bottom, papers, initSol);
    printSol(sol);
}