#include<stdio.h>
#include<string.h>
#define SIZE 100001
// #define db
int main(){
    char instr[SIZE];
    scanf("%s", instr);
    #ifdef db
    printf("instr = %s\n", instr);
    #endif
    char cmd[SIZE];
    while(scanf("%s", cmd) == 1){
        if(strcmp(cmd, "end") == 0) break;
        if(strcmp(cmd, "replace") == 0){
            char del[2], new[2];
            scanf("%s%s", del, new);
            int len = strlen(instr);
            for(int i = 0; i < len; i++){
                if(instr[i] == del[0])
                    instr[i] = new[0];
            }
        }//replace
        else if(strcmp(cmd, "remove") == 0){
            char del[2];
            scanf("%s", del);
            #ifdef db
            printf("%s %s\n", cmd, del);
            #endif
            int len = strlen(instr);
            int j = 0;
            for(int i = 0; i < len; i++){
                if(instr[i] != del[0]){
                    instr[j] = instr[i];
                    j++;
                }
            }
            instr[j] = '\0';
        }//remove
        else if(strcmp(cmd, "addhead") == 0){
            char add[2];
            scanf("%s", add);
            int len = strlen(instr);
            instr[len + 1] = '\0';
            for(int i = len - 1; i >= 0; i--){
                instr[i + 1] = instr[i];
            }
            instr[0] = add[0];
        }//add 
        else if(strcmp(cmd, "addtail") == 0){
            char add[2];
            scanf("%s", add);
            strcat(instr, add);
        }//add 
        else{
            printf("invalid command %s\n", cmd);
            return 0;
        }
    }//while
    printf("%s\n", instr);
    return 0;
}