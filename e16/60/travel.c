#include<stdio.h>
#include<limits.h>
#define MAXN 14
int getMin(int a, int b){
    return a * (a < b) + b * (a >= b);
}
int findShort(int dists[MAXN][MAXN], int visit[], int needvisit,
int cost, int now, int n, int *shortest){
    if(cost > *shortest)
        return *shortest + 1;
    if(needvisit == 0)
        return(cost + dists[now][0]);
    for(int next = 1; next < n; next++){
        if(!visit[next]){
            visit[next] = 1;
            int dist = findShort(dists, visit, needvisit - 1, cost + dists[now][next], next, n, shortest);
            *shortest = getMin(dist, *shortest);
            visit[next] = 0;
        }
    }
    return *shortest;
}
int main(){
    int n, dists[MAXN][MAXN];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &dists[i][j]);
        }
    }
    int visit[MAXN] = {0};
    int shortest = INT_MAX;
    findShort(dists, visit, n - 1, 0, 0, n, &shortest);
    printf("%d\n", shortest);
}