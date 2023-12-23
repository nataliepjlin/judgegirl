#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 101
// #define debug
int main(){
    char str[SIZE];
    while(fgets(str, SIZE, stdin) != NULL){
        #ifdef debug
        printf("init str = \"%s\"\n", str);
        #endif
        int head = 0, tail = strlen(str) - 1;
        while(str[tail] == '\n' || isspace(str[tail])){
            tail --;
        }
        while(isspace(str[head])){
            head ++;
        }
        #ifdef debug
        printf("head = %d, tail = %d\n", head, tail);
        #endif
        char tmp[SIZE];
        strncpy(tmp, str + head, tail - head + 1);
        tmp[strlen(tmp) + 1] = '\0';
        strcpy(str, tmp);
        printf("%s\n", str);
    }
    return 0;
}