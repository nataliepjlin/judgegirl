#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#define N 11
// #define debug
int max(int a, int b){
    return a * (a > b) + b * (a <= b);
}
int getdist(char *result, int f[N][N], int n, int new){
    int dist = 0;
    for(int i = 0; i < n; i++){
        if(f[new][result[i] - 'A']){
            dist = (n - i);
            break;
        }
    }
    return dist;
}
int min(int a, int b){
    return a * (a < b) + b * (a >= b);
}
void perm(int idx, int used[], int n, char result[], int *mindist, int f[N][N], char ans[], int nowmax){
    if(nowmax >= *mindist){
        result[idx - 1] = 0;
        return;
    }
    if(idx == n){
       if(*mindist > nowmax){
        *mindist = nowmax;
        strcpy(ans, result);
       }
       return;
    }
    for(int i = 0; i < n; i++){
        if(!used[i]){
            int newmax = max(nowmax, getdist(result, f, idx, i));\
            used[i] = 1;
            result[idx] = 'A' + i;
            perm(idx + 1, used, n, result, mindist, f, ans, newmax);
            used[i] = 0;
        }
    }
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int used[N] = {0};
    char result[N] = {0};
    int f[N][N] = {{0}};
    char p1[2], p2[2];
    for(int i = 0; i < m; i++){
        scanf("%s%s", p1, p2);
        f[p1[0] - 'A'][p2[0] - 'A'] = 1;
        f[p2[0] - 'A'][p1[0] - 'A'] = 1;
    }
    int mindist = INT_MAX;
    char ans[N];
    perm(0, used, n, result, &mindist, f, ans, 0);
    printf("%d\n", mindist);
    for(int i = 0; i < n; i++){
        printf("%c%c", ans[i], " \n"[i == n - 1]);
    }
}