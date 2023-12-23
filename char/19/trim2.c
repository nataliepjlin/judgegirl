#include<stdio.h>
#include<string.h>
#include<ctype.h>
// #define DEBUG
int main(){
    char str[100];
    char c;
    int idx;
    while (1) {
        if (scanf("%99[^\n]%*c", str) != 1) {
            break; // Exit the loop when scanf fails to read a string
        }
        #ifdef DEBUG
        printf("now %s\n", str);
        #endif
        idx = strlen(str);
        while(isspace(str[idx - 1])){
            strncpy(str, str, strlen(str) - 1);
            str[idx - 1] = '\0';
            idx --;
            #ifdef DEBUG
            printf("trimmed %s\n", str);
            #endif
        }
        while(isspace(str[0])){
            memmove(str, str + 1, strlen(str));
            idx --;
            #ifdef DEBUG
            printf("trimmed %s\n", str);
            #endif
        }
        printf("%s\n", str);
        memset(str, '\0', strlen(str) * sizeof(char));
        idx = 0;
        #ifdef DEBUG
        printf("after kill, str = %s\n", str);
        #endif
    }
    return 0;
}
