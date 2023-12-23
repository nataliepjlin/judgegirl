#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1001
#define E 150000
void printperm(int steps[], int s){
    for(int i = 0; i < s; i++){
        printf("%d%c", steps[i], " \n"[i == s - 1]);
    }
}
int trav(int n, int steps[], int s, int roads[n][n], int visited[], int prev){
    #ifdef debug
    printf("in trav\n");
    printperm(steps, s);
    #endif
    if(s == n){
        steps[n] = steps[0];
        return 1;
    }
    for(int i = 0; i < n; i++){
        if(visited[i] || (prev != -1 && !roads[prev][i])
        || (s == n - 1 && !roads[i][steps[0]])) continue;
        visited[i] = 1;
        steps[s] = i;
        if(trav(n, steps, s + 1, roads, visited, i))
            return 1;
        visited[i] = 0;
    }
    return 0;
}
int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int main(){
    int n, e;
    scanf("%d%d", &n, &e);
    int roads[n][n]; memset(roads, 0, sizeof(roads));
    int c1, c2;
    for(int i = 0; i < e; i++){
        scanf("%d%d", &c1, &c2);
        roads[c1][c2] = 1;
        roads[c2][c1] = 1;
    }
    int visited[N] = {0};
    int steps[N + 1];
    if(trav(n, steps, 0, roads, visited, -1)){
        #ifdef debug
        printf("in main\n");
        #endif
        printperm(steps, n + 1);
    }
    else printf("NO SOLUTION\n");
}