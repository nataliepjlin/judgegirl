#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 50
#define MAXL 11
// #define debug
void swap(char *str1, char *str2){
    char tmp[MAXL];
    strcpy(tmp, str1);
    strcpy(str1, str2);
    strcpy(str2, tmp);
}
void bsOutput(char str[][MAXL]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3 - i - 1; j++){
            if(strcmp(str[j], str[j + 1]) > 0){
                swap(str[j], str[j + 1]);
            }
        }
    }
}
void getMean(int members[], int idx, char str[][MAXL], char means[MAXL], int l){
    int sum[MAXL] = {0};
    for(int i = 0; i < l; i++){
        for(int j = 0; j < idx; j++){
            sum[i] += str[members[j]][i];
        }
        means[i] = sum[i] / idx;
    }
}
int getDist(char *str1, char *str2, int l){
    int dist = 0;
    for(int i = 0; i < l; i++){
        dist += abs(str1[i] - str2[i]);
    }
    return dist;
}
int getLeader(int members[], int idx, char str[][MAXL], int l, char means[MAXL]){
    int leader = 0;
    for(int i = 1; i < idx; i++){
        if(getDist(str[members[leader]], means, l) > getDist(str[members[i]], means, l)
        || (getDist(str[members[leader]], means, l) == getDist(str[members[i]], means, l)
        && strcmp(str[members[leader]], str[members[i]]) > 0)){
            leader = i;
        }
    }
    return leader;
    
}
int main(){
    int n, l, round;
    scanf("%d%d%d", &n, &l, &round);
    char str[MAXN][MAXL];
    int sums[MAXN] = {0};
    int members[3][MAXN] = {{0}};
    int idx[3] = {1, 1, 1};
    for(int i = 0; i < n; i++){
        scanf("%s", str[i]);
    }
    
    for(int r = 0; r < round; r++){
        members[0][0] = 0, members[1][0] = 1, members[2][0] = 2;
        idx[0] = 1, idx[1] = 1, idx[2] = 1;
        for(int i = 3; i < n; i++){
            int d0 = getDist(str[0], str[i], l),
            d1 = getDist(str[1], str[i], l),
            d2 = getDist(str[2], str[i], l);
            int min = ((d1 < d0 || (strcmp(str[0], str[1]) > 0 && d0 == d1)) 
            && (d1 < d2 || (strcmp(str[2], str[1]) > 0 && d1 == d2))) \
            + ((d2 < d0 || (strcmp(str[0], str[2]) > 0 && d0 == d2)) 
            && (d2 < d1 || (strcmp(str[1], str[2]) > 0 && d1 == d2))) * 2;
            members[min][idx[min]] = i;
            idx[min] ++;
        }
        for(int g = 0; g < 3; g++){
            #ifdef debug
            for(int i = 0; i < idx[g]; i++){
                printf("%s%c", str[members[g][i]], " \n"[i == idx[g] - 1]);
            }
            printf("\n");
            #endif
            char means[MAXL] = {0};
            getMean(members[g], idx[g], str, means, l);
            int new = getLeader(members[g], idx[g], str, l, means);
            swap(str[members[g][0]], str[members[g][new]]);
        }//new leader
    }//round
    bsOutput(str);
    printf("%s\n%s\n%s\n", str[0], str[1], str[2]);
    return 0;
}