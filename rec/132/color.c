#include<stdio.h>
#define MAXN 20
// #define debug
typedef struct{
    int idx;
    int arr[MAXN];
}NEIGHBOR;
int mark(int color, int i, NEIGHBOR neighbors[], int map[], int n){
    if(i == n){
        for(int j = 0; j < n; j++){
            printf("%d\n", map[j]);
        }
        return 1;
    }
    for(int c = 1; c <= color; c++){
        int conflict = 0;
        #ifdef debug
        printf("trying color %d\n", c);
        #endif
        for(int j = 0; j < neighbors[i].idx && !conflict; j++){
            #ifdef debug
            printf("%d/%dth neighbor(%d)'s color = %d\n", j + 1, neighbors[i].idx, neighbors[i].arr[j], map[neighbors[i].arr[j]]);
            #endif
            conflict = (map[neighbors[i].arr[j]] == c);
        }
        if(!conflict){
            map[i] = c;
            if(mark(color, i + 1, neighbors, map, n))
                return 1;
            map[i] = 0;
        }
    }
    return 0;
}
int main(){
    int n, c, p;
    scanf("%d%d%d", &n, &c, &p);
    NEIGHBOR neighbors[n];
    for(int i = 0; i < n; i++){
        neighbors[i].idx = 0;
    }
    int p1, p2;
    for(int i = 0; i < p; i++){
        scanf("%d%d", &p1, &p2);
        neighbors[p1].arr[neighbors[p1].idx] = p2;
        neighbors[p1].idx ++;
        neighbors[p2].arr[neighbors[p2].idx] = p1;
        neighbors[p2].idx ++;
    }
    #ifdef debug
    // for(int i = 0; i < n; i++){
    //     printf("\n%dth country\n", i);
    //     for(int j = 0; j < neighbors[i].idx; j++){
    //         printf("%d%c", neighbors[i].arr[j], " \n"[j == neighbors[i].idx - 1]);
    //     }
    // }
    #endif
    int map[MAXN] = {0};
    int ret = mark(c, 0, neighbors, map, n);
    if(!ret)
        printf("no solution.\n");
}