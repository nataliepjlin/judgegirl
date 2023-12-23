#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char str[101];
    while(fgets(str, 101, stdin) != NULL){
        int end = strlen(str) - 1;
        while(isspace(str[end])) end --;
        int foundFirstChar = 0;
        for(int i = 0; i <= end; i++){
            if(isspace(str[i]) && !foundFirstChar)
                continue;
            else
                foundFirstChar = 1;
            if(foundFirstChar)
                printf("%c", str[i]);
        }
        printf("\n");
    }
}