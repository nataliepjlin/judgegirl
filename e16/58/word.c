#include<stdio.h>
#include<limits.h>
#include<string.h>
// #define debug
#define N 20
#define CHAR 51
#define ALP 26
typedef struct{
    int cost;
    char str[CHAR];
}INFO;
int hasAll(int pick[]){
    for(int i = 0; i < ALP; i++){
        if(!pick[i])
            return 0;
    }
    return 1;
}
void mark(INFO info[], int idx, int pick[]){
    int len = strlen(info[idx].str);
    for(int i = 0; i < len; i++){
        pick[info[idx].str[i] - 'a'] ++;
    }
}
void unmark(INFO info[], int idx, int pick[]){
    int len = strlen(info[idx].str);
    for(int i = 0; i < len; i++){
        pick[info[idx].str[i] - 'a'] --;
    }
}
int min(int a, int b){
    return a * (a < b) + b * (a >= b);
}
int getCost(INFO info[], int idx, int n, int cost, int *mincost,
int pick[]){
    #ifdef debug
    printf("idx = %d, cost = %d, mincost = %d\n", idx, cost, *mincost);
    #endif
    if(hasAll(pick)){
        #ifdef debug
        printf("hasAll\n\n");
        #endif
        *mincost = min(*mincost, cost);
        return cost;
    }
    if(idx >= n || cost > *mincost){
        #ifdef debug
        printf("exceed\n\n");
        #endif
        return INT_MAX;
    }
    mark(info, idx, pick);
    #ifdef debug
    printf("get str[%d] = %s with %d\n", idx, info[idx].str, info[idx].cost);
    #endif
    getCost(info, idx + 1, n, cost + info[idx].cost, mincost, pick);
    unmark(info, idx, pick);
    getCost(info, idx + 1, n, cost, mincost, pick);
}
int main(){
    int n;
    INFO info[N];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s%d", info[i].str, &info[i].cost);
    }
    int mincost = INT_MAX, pick[ALP] = {0};
    getCost(info, 0, n, 0, &mincost, pick);
    printf("%d\n", mincost);
}