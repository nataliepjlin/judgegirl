#include<stdio.h>
#include<string.h>
#define SIZE 128
// #define debug
int main(){
    char out[SIZE], tmp[SIZE], tmpCut[SIZE], outCut[SIZE];
    memset(out, '\0', SIZE);
    memset(tmp, '\0', SIZE);
    memset(tmpCut, '\0', SIZE);

    while(scanf("%s", tmp) != EOF){
        #ifdef debug
        printf("\ntmp = %s\n", tmp);
        #endif
        int cat = 0;
        for(int i = strlen(tmp); i > 0 && !cat && strlen(out); i--){
            memset(tmpCut, '\0', SIZE);
            strncpy(tmpCut, tmp, i);
            #ifdef debug
            printf("i = %d, tmpCut = %s\n", i, tmpCut);
            #endif
            char outCut[SIZE]; memset(outCut, '\0', SIZE);
            if(strlen(tmpCut) > strlen(out)) continue;
            memset(outCut, '\0', SIZE);
            strncpy(outCut, out + (strlen(out) - strlen(tmpCut)), strlen(tmpCut));
            #ifdef debug
            printf("outCut = %s\n", outCut);
            #endif
            if(strcmp(outCut, tmpCut) == 0){
                if(i != strlen(tmp)){
                    strncat(out, tmp + i, strlen(tmp) - i);
                    #ifdef debug
                    printf("need to cat: ");
                    for(int t = i; t < strlen(tmp); t++){
                        printf("%c", tmp[t]);
                    }
                    printf("\n");
                    printf("now out = %s\n", out);
                    #endif
                }
                cat = 1;
            }
        }//for
        if(!cat){
            strcat(out, tmp);
            #ifdef debug
            printf("cat the whole %s to out\n", tmp);
            printf("now out = %s\n", out);
            #endif
        } 
    }
    printf("%s\n", out);
    return 0;
}