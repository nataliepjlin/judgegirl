#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 80000
#define MAXCHAR 101
// #define debug
int min(int a, int b){
    return a * (a < b) + b * (a >= b);
}
int type1(char query[MAXCHAR], char dictI[MAXCHAR]){
    int print = 0;
    int qlen = strlen(query), dlen = strlen(dictI);
    int diff = (qlen != dlen) * 2;
    for(int l = 0;  diff < 2 && l < qlen; l++){
        diff += (query[l] != dictI[l]);
    }
    print = (diff < 2);
    return print;
}
int type2(char query[MAXCHAR], char dictI[MAXCHAR]){
    int qlen = strlen(query), dlen = strlen(dictI);
    if(qlen != dlen + 1) return 0;
    int q = 0, d = 0;
    int add = 0;
    for(int i = 0; i < qlen; i++){
        #ifdef debug
        printf("comparing query[%d] = %c, dictI[%d] = %c\n", q, query[q], d, dictI[d]);
        #endif
        if(query[q] == dictI[d]){
            q++;
            d++;
        }
        else{
            if(add) return 0;
            else{
                add = 1;
                q++;
            } 
        }
    }
    return add;
}
int type3(char query[MAXCHAR], char dictI[MAXCHAR]){
    int qlen = strlen(query), dlen = strlen(dictI);
    if(qlen + 1 != dlen) return 0;
    int q = 0, d = 0;
    int remove = 0;
    for(int i = 0; i < dlen; i++){
        #ifdef debug
        printf("comparing query[%d] = %c, dictI[%d] = %c\n", q, query[q], d, dictI[d]);
        #endif
        if(query[q] == dictI[d]){
            q++;
            d++;
        }
        else{
            if(remove) return 0;
            else{
                remove = 1;
                d++;
            } 
        }
    }
    return remove;
}
int main(){
    int n, q;
    scanf("%d", &n);
    char dict[MAXN][MAXCHAR];
    for(int i = 0; i < n; i++){
        scanf("%s", dict[i]);
    }
    
    scanf("%d", &q);
    char query[MAXCHAR];
    int same[MAXN] = {0};
    for(int i = 0; i < q; i++){
        scanf("%s", query);
        int printed = 0;
        for(int d = 0; d < n && !printed; d++){
            if(strcmp(dict[d], query) == 0){
                printf(">%s\n", query);
                printed = 1;
            }
        }//same
        if(!printed){
            for(int d = 0; d < n; d++){
                #ifdef debug
                printf("dict[%d] = %s\n", d, dict[d]);
                #endif
                if(type1(query, dict[d]) || type2(query, dict[d]) || type3(query, dict[d])){
                    (!printed) ? printf("?%s", dict[d]) : printf(" %s", dict[d]);
                    printed ++;
                }
            }
            if(!printed) printf("!%s", query);
            printf("\n");
        }//ensured no same
    }
    return 0;
}