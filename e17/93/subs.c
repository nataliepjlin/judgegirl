#include<stdio.h>
#include<string.h>
#define MAXCHAR 1024
int main(){
    char str[MAXCHAR];
    scanf("%s", str);
    char cmd[MAXCHAR];
    while(scanf("%s", cmd) == 1){
        if(cmd[0] == 's'){
            char deli[2] = {0};
            deli[0] = cmd[1];
            char *old = strtok(cmd + 2, deli);
            char *found = strstr(str, old);
            if(found != NULL){
                char *new = strtok(NULL, deli);
                #ifdef debug
                printf("\nold = %s, new = %s\n", old, new);
                #endif
                int len1 = strlen(old), len2 = strlen(new);
                strcpy(found + len2, found + len1);
                for(int i = 0; i < len2; i++){
                    found[i] = new[i];
                }
            }
        }//s
        else{
            printf("%s\n", str);
        }
    }
}