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
            char *new = strtok(NULL, deli);
            #ifdef debug
            printf("\nold = %s, new = %s\n", old, new);
            #endif
            char *found = strstr(str, old);
            if(found != NULL){
                int idx =  found - str;
                int len = strlen(str);
                int len1 = strlen(old), len2 = strlen(new);
                int n = 0;
                #ifdef debug
                printf("idx = %d\n", idx);
                #endif 
                char tmp[MAXCHAR] = {0};
                int t = 0;
                for(int i = 0; i < idx; i++, t++){
                    tmp[t] = str[i];
                }
                for(int i = 0; i < len2; i++, t++){
                    tmp[t] = new[i];
                }
                for(int i = idx + len1; i < len; i++, t++){
                    tmp[t] = str[i];
                }
                strcpy(str, tmp);
            }
        }//s
        else{
            printf("%s\n", str);
        }
    }
}