#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 128
// #define debug
int main(){
    char tmp[SIZE], abbr[SIZE];
    while(scanf("%s", tmp) != EOF){
        #ifdef debug
        printf("tmp = %s\n", tmp);
        #endif
        char trim[SIZE]; memset(trim, '\0', SIZE);
        if(tmp[strlen(tmp) - 1] == '.'){
            strncpy(trim, tmp, strlen(tmp) - 1);
            trim[strlen(trim) + 1] = '\0';
        }
        else{
            strcpy(trim, tmp);
        }
        if((strcmp(trim, "of") && strcmp(trim, "and")
        && strcmp(trim, "the") && strcmp(trim, "at"))){
            printf("%c", toupper(trim[0]));
        }
        if(tmp[strlen(tmp) - 1] == '.'){
            printf("\n");
        }
    }
    return 0;
}