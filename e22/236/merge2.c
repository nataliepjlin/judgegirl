#include<stdio.h>
#include<string.h>
#define LSIZE 26
#define debug
int findMin(char **P, int intL[LSIZE]){
    int min = -1, minLoc = -1;
    for(int p = 0; P[p] != NULL; p++){
        char c = P[p][0];
        if(c != '\0' && (min == -1 || minLoc > intL[c - 'a'])){
            min = p;
            minLoc = intL[c - 'a'];
        }
    }
    return min;
}
void mergeString(char** P, char L[26], char* A){
    int intL[LSIZE];
    for(int i = 0; i < LSIZE; i++){
        intL[L[i] - 'a'] = i;
    }
    int a = 0, p = findMin(P, intL);
    while(p != -1){
        A[a] = P[p][0];
        a++;
        P[p] ++;
        p = findMin(P, intL);
    }
    A[a] = '\0';
}