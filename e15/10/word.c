#include<stdio.h>
#include<string.h>
#define MAX 100001
// #define debug
int main(){
    char str[MAX];
    scanf("%s", str);
    char cmd[8];
    char x[2], y[2];
    while(scanf("%s", cmd) == 1){
        int len = strlen(str);
        if(strcmp("end", cmd) == 0)
            break;
        else if(strcmp("replace", cmd) == 0){
            scanf("%s%s", x, y);
            for(int i = 0; i < len; i++){
                str[i] = y[0] * (x[0] == str[i]) + str[i] * !(x[0] == str[i]);
            }
        }
        else if(strcmp("addtail", cmd) == 0){
            scanf("%s", x);
            strcat(str, x);
        }
        else if(strcmp("addhead", cmd) == 0){
            scanf("%s", x);
            for(int i = len - 1; i >= 0; i--){
                str[i + 1] = str[i];
            }
            str[0] = x[0];
        }
        else if(strcmp("remove", cmd) == 0){
            scanf("%s", x);
            char *ptr = strchr(str, x[0]);
            while(ptr != NULL){
                int idx = ptr - str;
                #ifdef debug
                printf("idx = %d\n", idx);
                #endif
                memmove(str + idx, str + idx + 1, len - idx);
                ptr = strchr(str + idx, x[0]);
            }
        }
        else{
            printf("invalid command %s\n", cmd);
            return 0;
        }
    }
    printf("%s\n", str);
    return 0;
}