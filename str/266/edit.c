#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXCHAR 11
#define MAXSIZE 100
// #define debug
int idxCmp(int id1, int id2){
    return 1000 * (id1 + 1) + (id2 + 1);
}
int min(int a, int b){
    return a * (a < b) + b * (a >= b);
}
int getDist(char str1[], char str2[]){
    int len1 = strlen(str1), len2 = strlen(str2);
    if(!len1 || !len2) return abs(len1 - len2);
    if(str1[0] == str2[0]) return getDist(str1 + 1, str2 + 1);
    return 1 + min(getDist(str1 + 1, str2), getDist(str1, str2 + 1));
}
int main(){
    char str[MAXSIZE][MAXCHAR];
    int idx = 0;
    while(scanf("%s", str[idx]) == 1){
        idx++;
    }
    int min = -1, id1 = -1, id2 = -1;
    for(int i = 0; i < idx; i++){
        for(int j = i + 1; j < idx; j++){
            int dist = getDist(str[i], str[j]);
            #ifdef debug
            printf("dist = %d\n", dist);
            #endif
            if(min == -1
            || min > dist
            || min == dist && idxCmp(id1, id2) > idxCmp(i, j)){
                min = dist;
                id1 = i;
                id2 = j;
            }//if
        }//j
    }//i
    printf("%d %d %d\n", min, id1 + 1, id2 + 1);
    return 0;
}