#include<stdio.h>
#define MAXN 105
#define MAXS MAXN * MAXN
#define MAXC 10

#define KEY 0
#define IDX 1

// #define debug
int f(int key, int S){
    return (77 * key + 2222) % S;
}
int max(int a, int b){
    return a * (a > b) + b * (a <= b);
}
void getTower(int N, int tower[MAXN][MAXN][MAXN]){
    for(int l = 1; l <= N; l++){
        for(int r = 0; r < l; r++){
            for(int c = 0; c < l; c++){
                scanf("%d", &tower[r][c][N - l]);
            }
        }
    }
}
void computeHeight(int N, int height[MAXN][MAXN]){
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            height[r][c] = N - max(r, c);
        }
    }
}
void insert(int hashT[MAXS][MAXC][2], int key, int S, int towerIdx){
    int hashVal = f(key, S);
    for(int i = 0; i < MAXC; i++){
        if(hashT[hashVal][i][KEY] == 0){
            #ifdef debug
            printf("insert %d to hashT\n", key);
            #endif
            hashT[hashVal][i][KEY] = key;
            hashT[hashVal][i][IDX] = towerIdx;
            return;
        }
    }
}
int findRemove(int hashT[MAXS][MAXC][2], int key, int S, int towerIdx){
    int hashVal = f(key, S);
    for(int i = 0; i < MAXC; i++){
        if(hashT[hashVal][i][KEY] == key){
            hashT[hashVal][i][KEY] = 0;
            return hashT[hashVal][i][IDX];
        }
    }
    return -1;
}
void pairing(int pair[2], int row[2], int col[2], int height[MAXN][MAXN], int tower[MAXN][MAXN][MAXN]
, int newTidx[2], int oldTidx[2], int hashT[MAXS][MAXC][2], int S){
    for(int i = 0; i < 2; i++){
        pair[i] = 0;
        newTidx[i] = -1;
        if(height[row[i]][col[i]] > 0){
            newTidx[i] = findRemove(hashT, tower[row[i]][col[i]][height[row[i]][col[i]] - 1], S, oldTidx[i]);
            if(newTidx[i] == -1){
                insert(hashT, tower[row[i]][col[i]][height[row[i]][col[i]] - 1], S, oldTidx[i]);
            }
            else{
                pair[i] = 1;
            }
        }
    }
}
int main(){
    int N, S, C;
    int tower[MAXN][MAXN][MAXN] = {{{0}}}, height[MAXN][MAXN] = {{0}};
    scanf("%d%d%d", &N, &S, &C);
    getTower(N, tower);
    computeHeight(N, height);
    int hashT[MAXS][MAXC][2] = {{{0}}};
    int towerIdx = 0, paired = 0;
    int oldTidx[2] = {0};
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++, towerIdx++){
            int layer = height[r][c] - 1;
            int hashVal = f(tower[r][c][layer], S);
            int same = findRemove(hashT, tower[r][c][layer], S, towerIdx);
            if(same == -1){
                insert(hashT, tower[r][c][layer], S, towerIdx);
            }
            else{
                paired = 1;
                oldTidx[0] = same;
                oldTidx[1] = towerIdx;
            }
        }
    }
    while(paired){
        int row[2] = {oldTidx[0] / N, oldTidx[1] / N};
        int col[2] = {oldTidx[0] % N, oldTidx[1] % N};
        printf("%d ", tower[row[0]][col[0]][height[row[0]][col[0]] - 1]);
        height[row[0]][col[0]] --;
        height[row[1]][col[1]] --;
        if(height[row[0]][col[0]] > 0 && height[row[1]][col[1]] > 0
        && tower[row[0]][col[0]][height[row[0]][col[0]] - 1] == tower[row[1]][col[1]][height[row[1]][col[1]] - 1]){
            paired = 1;
            continue;
        }
        int pair[2], newTidx[2];
        pairing(pair, row, col, height, tower, newTidx, oldTidx, hashT, S);
        paired = (pair[0] || pair[1]);
        if(paired){
            if(pair[0]){
                oldTidx[1] = newTidx[0];
            }
            else{
                oldTidx[0] = newTidx[1];
            }
        }
    }
    #ifdef debug
    printf("\n");
    #endif
    return 0;
}