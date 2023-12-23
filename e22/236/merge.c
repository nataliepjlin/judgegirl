#include<stdio.h>
#include<string.h>
#define LSIZE 26
#define debug
int findMin(char **P, char L[26]){
    int min = -1;
    char *minLoc;
    for(int p = 0; P[p] != NULL; p++){
        char c = P[p][0];
        if(c != '\0' && (min == -1 || minLoc > strchr(L, c))){
            min = p;
            minLoc = strchr(L, c);
        }
    }
    return min;
}
void mergeString(char** P, char L[26], char* A){
    int a = 0, p = findMin(P, L);
    while(p != -1){
        A[a] = P[p][0];
        a++;
        P[p] ++;
        p = findMin(P, L);
    }
    A[a] = '\0';
}