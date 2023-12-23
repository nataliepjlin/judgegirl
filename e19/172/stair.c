#include<stdio.h>
#include<string.h>
#define MAXCHAR 32
// #define debug
void printStar(int n){
    for(int i = 0; i < n; i++){
        printf("*");
    }
}
int main(){
    char prev[MAXCHAR];
    scanf("%s", prev);
    printf("%s\n", prev);
    int prevlen = strlen(prev);
    char input[MAXCHAR];
    int round = 1, stars = prevlen - 1;
    while(scanf("%s", input) == 1){
        int idx = 0;
        int len = strlen(input);
        idx += (input[0] == prev[prevlen - 1]);
        #ifdef debug
        printf("\nidx = %d\n", idx);
        #endif
        if(round % 2){//vertical
            for(int i = idx; i < len; i++){
                printStar(stars);
                printf("%c", input[i]);
                if(i < len - 1) printf("\n");
            }
        }
        else{//horizontal
            if(!idx){
                printf("\n");
                printStar(stars);
            }
            printf("%s\n", input + idx);
            stars += (len - 1);
        }
        prevlen = len;
        strcpy(prev, input);
        round ++;
    }
}