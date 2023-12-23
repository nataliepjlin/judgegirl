#include<stdio.h>
#include<string.h>
#define MAX 256
// #define debug
int main(){
    char out[MAX] = {0};
    char now[MAX / 2];
    while(scanf("%s", now) == 1){
        int outlen = strlen(out);
        int nowlen = strlen(now);
        int cpylen = nowlen;
        int same = 0;
        for(int i = nowlen; i > 0 && !same; i--, cpylen --){
            if(i > outlen) continue;
            char nowCut[MAX / 2] = {0}, outCut[MAX / 2] = {0};
            strncpy(nowCut, now, i);
            strncpy(outCut, out + (outlen - i), i);
            #ifdef debug
            printf("nowCut = %s, outCut = %s\n", nowCut, outCut);
            #endif
            same = (strcmp(nowCut, outCut) == 0);
        }
        cpylen += (same);
        strcat(out, now + cpylen);
        #ifdef debug
        printf("out = %s\n\n", out);
        #endif
    }
    printf("%s\n", out);
    return 0;
}