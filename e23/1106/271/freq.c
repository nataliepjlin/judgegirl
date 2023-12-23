#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#define MAXVAR 35
#define MAXCHAR 35
// #define debug
int checkPrev(char *s, char var[MAXVAR][MAXCHAR], int v){
    char tmpS[MAXCHAR] = {0};
    strncpy(tmpS, s, 24);
    for(int i = 0; i < v; i++){
        char tmpV[MAXCHAR] = {0};
        strncpy(tmpV, var[i], 24);
        if(strcmp(tmpS, tmpV) == 0){
            return i;
        }
    }
    return -1;
}
int isvalid(char *str){
    char reserved[][8] = {"if", "else", "while", "for",
                          "switch", "case", "break", "return",
                          "void", "int", "float", "char"};
    int valid = 1;
    int len = strlen(str);
    for(int i = 0; i < len && valid; i++){
        valid = (isalpha(str[i]) || str[i] == '_' || ((isdigit(str[i]) && i)));
    }
    for(int r = 0; r < 12 && valid; r++){
        valid = (strcmp(reserved[r], str) != 0);
    }
    return valid;
}
int main(){
    char var[MAXVAR][MAXCHAR] = {{0}};
    int v = 0;
    int freq[MAXVAR] = {0};
    char delims[] = "`~//()[]{} \t;=,/><!@#$+-*/%^&*-";
    char input[1000];
    while(scanf("%s", input) == 1){
        char *s = strtok(input, delims);
        while(s != NULL){
            int valid = isvalid(s);
            if(valid){
                #ifdef debug
                printf("s = %s\n", s);
                #endif
                int idx = checkPrev(s, var, v);
                idx = idx * (idx != -1) + (v) * (idx == -1);
                strncpy(var[idx], s, 24);
                freq[idx] ++;
                v += (v == idx);
                assert(v <= 30);
                #ifdef debug
                printf("idx = %d, v = %d\n", idx, v);
                #endif
            }//valid
            s = strtok(NULL, delims);
        }//not null
    }//while
    for(int i = 0; i < v; i++){
        printf("%s %d\n", var[i], freq[i]);
    }
    return 0;
}