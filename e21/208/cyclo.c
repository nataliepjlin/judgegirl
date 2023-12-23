#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 128
// #define debug
int isKeyword(char *token){
    return ((strcmp(token, "if") == 0)
        || (strcmp(token, "while") == 0)
        || (strcmp(token, "case") == 0)
        || (strcmp(token, "for") == 0));
}
int isQ(char *token){
    while(*token != '\0'){
        if(*token == '?')
            return 1;
        token ++;
    }
    return 0;
}
int main(){
    int cc = 0;
    char line[SIZE];
    char delims[] = " \t\n{};()[]";
    while(fgets(line, SIZE, stdin) != NULL){
        char *tok = strtok(line, delims);
        while(tok != NULL){
            #ifdef debug
            printf("tok = %s, ", tok);
            #endif
            cc += (isKeyword(tok) || isQ(tok));
            #ifdef debug
            printf("cc = %d\n", cc);
            #endif
            tok = strtok(NULL, delims);
        }
    }
    printf("%d\n", cc);
    return 0;
}