#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define HASHSIZE 1000
#define MAXCHAR 21
#define HASHCAP 3
int isValid(char *input){
    int len = strlen(input);
    int valid = 1;
    for(int i = 0; i < len && valid; i++){
        valid = (isalpha(input[i]) || input[i] == '_'
        || (isdigit(input[i]) && i != 0));
    }
    return valid;
}
int f(char *s){
    int len = strlen(s);
    int hashVal = 0;
    for(int i = 0; i < len; i++){
        hashVal = (hashVal + s[i]) % HASHSIZE;
    }
}

int main(){
    char input[MAXCHAR];
    char hashT[HASHSIZE][HASHCAP][MAXCHAR] = {{{0}}};
    int count[HASHSIZE][HASHCAP] = {{0}};
    while(scanf("%s", input) == 1){
        if(isValid(input)){
            int hashVal = f(input);
            int found = 0;
            for(int i = 0; i < HASHCAP && !found; i++){
                if(strcmp(hashT[hashVal][i], input) == 0){
                    count[hashVal][i] ++;
                    printf("%s %d\n", input, count[hashVal][i]);
                    found = 1;
                }
                else if(count[hashVal][i] == 0){
                    strcpy(hashT[hashVal][i], input);
                    count[hashVal][i] ++;
                    printf("%s %d\n", input, count[hashVal][i]);
                    found = 1;
                }
            }
        }//isvalid
    }
    return 0;
}