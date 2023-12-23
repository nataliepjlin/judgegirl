#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 512
void printOut(char out[MAX][MAX], int idx, int charCount, int max){
    if(idx == 1){
        printf("%s", out[0]);
        int pad = abs(charCount - max) % max;
        for(int i = 0; i < pad; i++){
            printf(" ");
        }
        printf("\n");
        return;
    }
    int diff = max - charCount;
    int basePad = diff / (idx - 1), extraPad = diff % (idx - 1);
    for(int i = 0; i < idx; i++){
        printf("%s", out[i]);
        if(i == idx - 1){
            printf("\n");
            break;;
        }
        for(int j = 0; j < basePad; j++){
            printf(" ");
        }
        if(extraPad > 0){
            printf(" ");
            extraPad --;
        }
    }
}
int main(){
    int max;
    scanf("%d", &max);
    char out[MAX][MAX] = {{0}};
    int idx = 0, charCount = 0;
    char now[MAX] = {0};
    while(scanf("%s", now) == 1){
        int len = strlen(now);
        if(charCount + idx + len  <= max){
            strcpy(out[idx], now);
            charCount += len;
            idx++;
        }
        else{
            printOut(out, idx, charCount, max);
            strcpy(out[0], now);
            charCount = len;
            idx = 1;
        }
    }
    printOut(out, idx, charCount, max);
    return 0;
}