#include<stdio.h>
#include<string.h>
#define MAXN 10
// #define debug
int getNi(int lens[], int n){
    int ni = -1;
    for(int i = 0; i < n; i++){
        if(ni == -1 || lens[ni] > lens[i])
            ni = i;
    }
    return ni;
}
void splitAndMap(char*** ptr, char* str){
    int idxs[MAXN] = {0};
    int lens[MAXN] = {0};
    int n = 0;
    while(ptr[n] != NULL) n++;
    char *start = strtok(str, "*");
    while(start != NULL){
        #ifdef debug
        printf("start = %s\n", start);
        #endif
        int ni = getNi(lens, n);
        ptr[ni][idxs[ni]] = start;
        idxs[ni] ++;
        lens[ni] += strlen(start);
        start = strtok(NULL, "*");
    }
}