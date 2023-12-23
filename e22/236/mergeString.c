#include<stdio.h>
#include<string.h>
#define MAXCHAR 201
#define debug
void mergeString(char** P, char L[26], char* A){
    int i = 0;
    int j[MAXCHAR] = {0};
    int total = 0;
    for(; P[i] != NULL; i++){
        for(; P[i][j[i]] != '\0'; j[i]++){  
            total ++; 
        }
    }
    int nowj[MAXCHAR] = {0};
    for(int t = 0; t < total; t++){
        int min = -1;
        for(int nowi = 0; nowi < i; nowi++){
            if(nowj[nowi] == j[nowi]) continue;
            if(min == -1 || strchr(L, P[nowi][nowj[nowi]]) < strchr(L, P[min][nowj[min]])){
                min = nowi;
            }
        }
        A[t] = P[min][nowj[min]];
        nowj[min] ++;
    }
}