#include<stdio.h>
#include<string.h>
#define ALPHA 26
#define MAXTRAIN 101
// #define debug
int getNext(char *out, int table[ALPHA][ALPHA], int now, int threshold){
    int next = -1;
    for(int i = 0; i < ALPHA; i++){
        if((next == -1 || (table[now][next] < table[now][i]))
        && table[now][i] > threshold && strchr(out, 'a' + i) == NULL){
            next = i;
        }
    }
    #ifdef debug
    printf("next = %d\n", next);
    #endif
    return next;
}
int main(){
    int table[ALPHA][ALPHA] = {{0}};
    char training[MAXTRAIN];
    int threshold;
    scanf("%d", &threshold);
    int maxidx = 'z' - 'a', maxpair;
    int maxCount = 0;
    while(scanf("%s", training) == 1){
        int len = strlen(training);
        for(int i = 0; i < len - 1; i++){
            int now = training[i] - 'a', next = training[i + 1] - 'a';
            table[now][next] ++;
            if(table[now][next] > maxCount
            || (table[now][next] == maxCount && now < maxidx)){
                maxCount = table[now][next];
                maxidx = now;
                maxpair = next;
            }
        }
    }
    for(int i = 0; i < ALPHA; i++){
        for(int j = 0; j < ALPHA; j++){
            printf("%d%c", table[i][j], " \n"[j == ALPHA - 1]);
        }
    }
    char out[ALPHA + 1] = {0};
    out[0] = maxidx + 'a', out[1] = maxpair + 'a';
    #ifdef debug
    printf("now out = %s\n", out);
    #endif
    for(int i = 2; i < ALPHA; i++){
        #ifdef debug
        printf("now out = %s\n", out);
        #endif
        int next = getNext(out, table, out[i - 1] - 'a', threshold);
        if(next == -1){
            break;
        }
        out[i] = next + 'a';
    }
    printf("%s\n", out);
    return 0;
}