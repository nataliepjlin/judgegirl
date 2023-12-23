#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#define MAXCHAR 11
#define N 102
int f(int id1, int id2){
    return 1000 * id1 + id2;
}
int min(int a, int b){
    return a * (a < b) + b * (a >= b);
}
int edit(char str1[], char str2[], int nowdist, int *mindist){
    int len1 = strlen(str1), len2 = strlen(str2);
    if(!len1 || !len2){
        return (abs(len1 - len2));
    }
    if(nowdist + abs(len1 - len2) > *mindist)
        return N * N;
    if(str1[0] == str2[0]){
        return edit(str1 + 1, str2 + 1, nowdist, mindist);
    }
    nowdist ++;
    return 1 + min(edit(str1 + 1, str2, nowdist, mindist), edit(str1, str2 + 1, nowdist, mindist));
}
int main(){
    char strs[N][MAXCHAR];
    int n = 1;
    while(scanf("%s", strs[n]) == 1){
        n++;
    }
    int minDist = N * N + 1, minId1 = N + 1, minId2 = N + 1;
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int dist = edit(strs[i], strs[j], 0, &minDist);
            if(minDist > dist
            || minDist == dist && f(i, j) < f(minId1, minId2)){
                minDist = dist;
                minId1 = i, minId2 = j;
            }
        }
    }
    printf("%d %d %d\n", minDist, minId1, minId2);
}