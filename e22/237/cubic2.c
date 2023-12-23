#include<stdio.h>
#include<string.h>

#define MAXN 100
#define HASHTSIZE MAXN * MAXN
#define MAXCHAR 6
#define MAXCAP 10
// #define debug
int max(int a, int b){
    return a * (a > b) + b * (a <= b);
}
void getTower(char tower[MAXN][MAXN][MAXN][MAXCHAR], int N){
    for(int l = 1; l <= N; l++){
        for(int r = 0; r < l; r++){
            for(int c = 0; c < l; c++){
                scanf("%s", tower[r][c][N - l]);
            }
        }
    }
}
void computeHeight(int height[MAXN][MAXN], int N){
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            height[r][c] = N - max(r, c);
            // printf("height[%d][%d] = %d\n", r, c, height[r][c]);
        }
    }
}
int f(char *str, int S){
    int len = strlen(str), val = 0;
    for(int i = 0; i < len; i++){
        val = (val * 29 + (str[i] - 'a' + 1));
    }
    return val % S;
}
int findRemove(char hashT[HASHTSIZE][MAXCAP][MAXCHAR], int towerIdxInHashT[HASHTSIZE][MAXCAP]
, char *key, int S){
    int ans = -1;
    int hashVal = f(key, S);
    #ifdef debug
    printf("%s's hashVal = %d\n", key, hashVal);
    #endif
    for(int i = 0; i < MAXCAP; i++){
        if(strcmp(hashT[hashVal][i], key) == 0){
            printf("%s\n", key);
            hashT[hashVal][i][0] = '\0';
            ans = towerIdxInHashT[hashVal][i];
            return ans;
        }
    }
    return ans;
}

void insert(char hashT[HASHTSIZE][MAXCAP][MAXCHAR], int towerIdxInHashT[HASHTSIZE][MAXCAP], char *key, int tidx, int S){
    int hashVal = f(key, S);
    for(int i = 0; i < MAXCAP; i++){
        if(hashT[hashVal][i][0] == '\0'){
            strcpy(hashT[hashVal][i], key);
            towerIdxInHashT[hashVal][i] = tidx;
            #ifdef debug
            printf("hashT[%d][%d] = %s, towerIdxInHashT = %d\n", hashVal, i, key, towerIdxInHashT[hashVal][i]);
            #endif
            return;
        }
    }
}
char *getKey(char tower[MAXN][MAXN][MAXN][MAXCHAR], int height[MAXN][MAXN], int r, int c){
    return tower[r][c][height[r][c] - 1];
}
void pairing(int pair[2], char tower[MAXN][MAXN][MAXN][MAXCHAR], int height[MAXN][MAXN]
, int prevTidx[2], int newTidx[2], int row[2], int col[2]
, char hashT[HASHTSIZE][MAXCAP][MAXCHAR], int towerIdxInHashT[HASHTSIZE][MAXCAP], int S){
    for(int i = 0; i < 2; i++){
        newTidx[i] = -1;
        pair[i] = 0;
        if(height[row[i]][col[i]] > 0){
            char *key = getKey(tower, height, row[i], col[i]);
            #ifdef debug
            printf("%dth's key = %s\n", i, key);
            #endif
            newTidx[i] = findRemove(hashT, towerIdxInHashT, key, S);
            if(newTidx[i] == -1){
                #ifdef debug
                printf("insert\n");
                #endif
                insert(hashT, towerIdxInHashT, key, prevTidx[i], S);
            }
            else{
                pair[i] = 1;
            }
        }
        else{
            #ifdef debug
            printf("%dth's height < 1\n", i);
            #endif
        }
    }
}
int main(){
    char tower[MAXN][MAXN][MAXN][MAXCHAR];
    int height[MAXN][MAXN];
    int N;
    scanf("%d", &N);
    int S = N * N;
    getTower(tower, N);
    computeHeight(height, N);
    char hashT[HASHTSIZE][MAXCAP][MAXCHAR] = {{{0}}};
    int towerIdxInHashT[HASHTSIZE][MAXCAP] = {{0}};
    int tidx = 0;
    int prevTidxs[2] = {0};
    int paired = 0;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++, tidx ++){
            char *key = getKey(tower, height, r, c);
            int ans = findRemove(hashT, towerIdxInHashT, key, S);
            if(ans == -1){
                insert(hashT, towerIdxInHashT, key, tidx, S);
            }
            else{
                prevTidxs[0] = ans;
                prevTidxs[1] = tidx;
                paired = 1;
            }
        }
    }
    //start pairing again
    while(paired){
        int row[2] = {prevTidxs[0] / N, prevTidxs[1] / N};
        int col[2] = {prevTidxs[0] % N, prevTidxs[1] % N};
        int newTidx[2], pair[2];
        height[row[0]][col[0]] --, height[row[1]][col[1]] --;
        if(height[row[0]][col[0]] > 0 && height[row[1]][col[1]] > 0
        && tower[row[0]][col[0]][height[row[0]][col[0]] - 1] == tower[row[1]][col[1]][height[row[1]][col[1]] - 1]){
            paired = 1;
            continue;
        }
        pairing(pair, tower, height, prevTidxs, newTidx, row, col, hashT, towerIdxInHashT, S);
        paired = (pair[0] || pair[1]);
        if(paired){
            if(pair[0]){
                prevTidxs[1] = newTidx[0];
            }
            else{
                prevTidxs[0] = newTidx[1];
            }
        }
    }
    
    return 0;
}
