#include<stdio.h>
#include<string.h>
#define MAX 50000
// #define debug
int main(){
    char insdel[7], loc[6], ele[2];
    char out[MAX], maxchar[MAX];
    while(scanf("%s", insdel) == 1){
        if(!strcmp(insdel, "insert")){
            scanf("%s%s", loc, ele);
            if(!strcmp(loc, "left")){
                int len = strlen(out);
                out[len + 1] = '\0';
                for(int i = len - 1; i >= 0; i--){
                    out[i + 1] = out[i];
                }
                out[0] = ele[0];
            }
            else if(!strcmp(loc, "right")){
                strcat(out, ele);
            }
            else{
                int idx = 0;
                int loclen = strlen(loc);
                for(int l = 0; l < loclen; l++){
                    idx = idx * 10 + (loc[l] - '0');
                }
                idx --;
                #ifdef debug
                printf("idx = %d\n", idx);
                #endif
                int len = strlen(out);
                out[len + 1] = '\0';
                for(int i = len - 1; i >= idx; i--){
                    out[i + 1] = out[i];
                }
                out[idx] = ele[0];
            }
        }//insert
        else{
            scanf("%s", loc);
            #ifdef debug
            printf("%s %s\n", insdel, loc);
            #endif
            int idx = 0, len = strlen(out);
            if(!strcmp(loc, "left")) idx = 0;
            else if(!strcmp(loc, "right")) idx = len - 1;
            else{
                int loclen = strlen(loc);
                for(int l = 0; l < loclen; l++){
                    idx = idx * 10 + (loc[l] - '0');
                }
                idx --;
            }
            #ifdef debug
            printf("del idx = %d\n", idx);
            #endif
            memmove(out + idx, out + idx + 1, strlen(out) - idx);
        }
        #ifdef debug
        printf("now out = %s\n", out);
        #endif
    }
    char prev = 0;
    int len = strlen(out), count = 0;
    int max = 0;
    for(int l = 0; l < len; l++){
        #ifdef debug
        printf("\nprev = %c, now count = %d, max = %d\n", prev, count, max);
        #endif
        if(prev != out[l]){
            if(max < count){
                memset(maxchar, '\0', MAX);
                maxchar[0] = prev;
                max = count;
            }
            else if(max == count){
                int slen = strlen(maxchar);
                maxchar[slen] = ' ';
                maxchar[slen + 1] = prev;
                maxchar[slen + 2] = '\0';
            }
            count = 1;
        }
        else count ++;
        prev = out[l];
    }
    if(max < count){
        memset(maxchar, '\0', MAX);
        maxchar[0] = prev;
        max = count;
    }
    else if(max == count){
        int slen = strlen(maxchar);
        maxchar[slen] = ' ';
        maxchar[slen + 1] = prev;
        maxchar[slen + 2] = '\0';
    }
    if(max) printf("%s ", maxchar);
    printf("%d\n", max);
    return 0;
}