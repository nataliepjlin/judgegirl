#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXCHAR 128
int main(){
    char input[MAXCHAR];
    while(scanf("%s", input) == 1){
        int len = strlen(input);
        if(strcmp(input, "of") && strcmp(input, "and") && strcmp(input, "the") && strcmp(input, "at")
        && strcmp(input, "of.") && strcmp(input, "and.") && strcmp(input, "the.") && strcmp(input, "at.")){
            printf("%c", input[0] - ('a' - 'A'));
        }
        if(input[len - 1] == '.') printf("\n");
    }
    return 0;
}