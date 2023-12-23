#include<stdio.h>
#define MAX 512
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void bs(int *ans[MAX], int reach[MAX], int idx){
    for(int i = 0; i < idx; i++){
        for(int j = 0; j < idx - i - 1; j++){
            if(reach[j] > reach[j + 1]
            || reach[j] == reach[j + 1] && *ans[j] > *ans[j + 1]){
                swap(ans[j], ans[j + 1]);
                swap(&reach[j], &reach[j + 1]);
            }
        }
    }
}
void count(int **p[]){
    int *ans[MAX], idx = 0;
    int reach[MAX] = {0};
    for(int i = 0; p[i] != NULL; i++){
        int found = 0, j;
        for(j = 0; j < idx && !found; j++){
            found = (ans[j] == *p[i]);
        }
        j -= (found == 1);
        ans[j] = *p[i];
        reach[j] ++;
        idx += (idx == j);
    }
    bs(ans, reach, idx);
    for(int i = 0; i < idx; i++){
        printf("%d %d\n", *ans[i], reach[i]);
    }
}