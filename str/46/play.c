#include<stdio.h>
#include<string.h>
#define MAX 50000
// #define debug
int main(){
    char outstr[MAX], tmp[MAX];
    char cmd[20];
    char ope[7], idx[6], x[2];
    while ((scanf("%99[^\n]%*c", cmd) == 1)) {
        #ifdef debug
        printf("cmd = %s\n", cmd);
        #endif
        int len = strlen(cmd);
        while(cmd[len - 1] == ' '){
            strncpy(cmd, cmd, strlen(cmd) - 1);
            cmd[len - 1] = '\0';
            len --;
        }//trim cmd
        strncpy(ope, cmd, 6);
        ope[6] = '\0';
        if(strcmp(ope, "insert") == 0){
            x[0] = cmd[strlen(cmd) - 1];
            memmove(cmd, cmd + 7, strlen(cmd));
            strncpy(idx, cmd, strlen(cmd) - 2);
            idx[strlen(idx)] = '\0';

            if(strcmp(idx, "right") == 0) strcat(outstr, x);
            else if(strcmp(idx, "left") == 0){
                memset(tmp, '\0', sizeof(tmp));
                tmp[0] = x[0];
                strcat(tmp, outstr);
                strcpy(outstr, tmp);
            } 
            else{//insert with idx
                memset(tmp, '\0', sizeof(tmp));
                int i = 0;
                #ifdef debug
                printf("strlen(idx) = %ld\n", strlen(idx));
                #endif
                for(int l = 0; l < strlen(idx); l++){
                    char c = idx[l];
                    i = i * 10 + (c - '0');
                    #ifdef debug
                    printf("now i = %d\n", i);
                    #endif
                }
                i --;
                #ifdef debug
                printf("idx = %s\n", idx);
                printf("i = %d\n", i);
                #endif
                strncpy(tmp, outstr, i);
                tmp[strlen(tmp)] = x[0];
                tmp[strlen(tmp)] = '\0';
                memmove(outstr, outstr + i, strlen(outstr));
                #ifdef debug
                printf("processed outstr = %s\n", outstr);
                printf("tmp = %s\n", tmp);
                #endif
                strcat(tmp, outstr);
                strcpy(outstr, tmp);
            }
        }
        else{
            memmove(cmd, cmd + 7, strlen(cmd));
            strncpy(idx, cmd, strlen(cmd));
            idx[strlen(idx)] = '\0';
            if(strcmp(idx, "right") == 0) memmove(outstr + strlen(outstr) - 1, outstr + strlen(outstr), 1);
            else if(strcmp(idx, "left") == 0) memmove(outstr, outstr + 1, strlen(outstr));
            else{
                int i = 0;
                #ifdef debug
                printf("strlen(idx) = %ld\n", strlen(idx));
                #endif
                for(int l = 0; l < strlen(idx); l++){
                    char c = idx[l];
                    i = i * 10 + (c - '0');
                    #ifdef debug
                    printf("now i = %d\n", i);
                    #endif
                }
                i --;
                #ifdef debug
                printf("i = %d\n", i);
                #endif
                memmove(outstr + i, outstr + (i + 1), strlen(outstr) - i);
            }
        }
        memset(idx, '\0', strlen(idx));
        memset(cmd, '\0', strlen(cmd));
        memset(ope, '\0', strlen(ope));
        #ifdef debug
        printf("now out = %s\n\n", outstr);
        #endif
    }
    int r, l, max = 0;
    char max_str[MAX * 2];
    int i = 0;
    while(i < strlen(outstr)){
        int count = 1;
        while(outstr[i] == outstr[i + count]){
            count ++;
        }
        char c = outstr[i]; 
        if(max < count){
            memset(max_str, '\0', strlen(max_str));
            max = count;
            max_str[strlen(max_str)] = c;
            max_str[strlen(max_str)] = '\0';
        }
        else if(max == count){
            max_str[strlen(max_str)] = ' ';
            max_str[strlen(max_str)] = c;
            max_str[strlen(max_str)] = '\0';
        }
        i += count;
        #ifdef debug
        printf("count = %d\n", count);
        printf("i = %d\n", i);
        #endif
    }
    if(strlen(max_str)) printf("%s ", max_str);
    printf("%d\n", max);
    return 0;
}