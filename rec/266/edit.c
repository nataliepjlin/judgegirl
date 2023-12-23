#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSTR 101
#define MAXCHAR 11
// #define debug
int cmp(int id1, int id2){
    return 1000 * id1 + id2;
}
int min(int a, int b){
    return a * (a < b) + b * (a >= b);
}
int getDist(char str1[], char str2[], int nowLen, int nowMin){
    #ifdef debug
    printf("now len = %d\n", nowLen);
    #endif
    int len1 = strlen(str1), len2 = strlen(str2);
    if(!len1 || !len2) return abs(len1 - len2);
    if(nowLen + abs(len1 - len2) > nowMin) return MAXSTR * MAXSTR;
    if(str1[0] == str2[0]){
        return getDist(str1 + 1, str2 + 1, nowLen, nowMin);
    }
    nowLen ++;
    return 1 + min(getDist(str1 + 1, str2, nowLen, nowMin), getDist(str1, str2 + 1, nowLen, nowMin));
}
int main(){
    char str[MAXSTR][MAXCHAR];
    int idx = 1;
    while(scanf("%s", str[idx]) == 1){
        idx++;
    }
    int min = MAXSTR * MAXSTR;
    int id1 = MAXSTR, id2 = MAXSTR;
    for(int i = 1; i < idx; i++){
        for(int j = i + 1; j < idx; j++){
            int dist = getDist(str[i], str[j], 0, min);
            if(dist < min
            || dist == min && cmp(id1, id2) > cmp(i, j)){
                min = dist;
                id1 = i;
                id2 = j;
            }
            #ifdef debug
            printf("\n");
            #endif
        }
    }
    printf("%d %d %d\n", min, id1, id2);
}