#include "mst.h"
#include <string.h>
void init(MST *mst, int N){
    mst->n = N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            mst->lens[i][j] = 0;
    }
}
void addRoad(MST *mst, int city1, int city2, int len){
    mst->lens[city1][city2] = len;
    mst->lens[city2][city1] = len;
    return;
}
int removeRoad(MST *mst, int city1, int city2){
    int l = mst->lens[city1][city2];
    mst->lens[city1][city2] = 0;
    mst->lens[city2][city1] = 0;
    return l;
}

void find(MST *mst, int now, int visited[]){
    for(int i = 0; i < mst->n; i++){
        if(!mst->lens[now][i]
        || visited[i]) continue;
        visited[i] = 1;
        find(mst, i, visited);
    }
}
bool hasPath(MST *mst, int a, int b){
    int visited[CITY] = {0};
    find(mst, a, visited);
    return (visited[b]);
}
 
bool connected(MST *mst){
    int visited[CITY] = {0};
    find(mst, 0, visited);
    int f = 1;
    for(int i = 0; i < mst->n && f; i++){
        f = visited[i];
    }
    return f;
}