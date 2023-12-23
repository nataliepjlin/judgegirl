#include<stdio.h>
#include<string.h>
#define MAX 10005
// #define debug
int main(){
    char str[MAX];
    int syl[MAX][2] = {{0}};
    int s1, s2;
    char vowels[] = "aeiouAEIOU";
    while(scanf("%s%d%d", str, &s1, &s2) == 3){
        int len = strlen(str);
        int idx = 0;
        for(int i = 0; i < len; i++){
            if(strchr(vowels, str[i]) != NULL){
                syl[idx][1] = i;
                idx++;
                syl[idx][0] = i + 1;
            }
        }
        for(int i = 0; i < len; i++){
            if(syl[s1][0] <= i && i <= syl[s1][1]){
                printf("%c", str[i]);
            }
            else{
                printf("+");
            }
        }
        printf("\n");
        //line 1
        for(int i = 0; i < len; i++){
            if(syl[s2][0] <= i && i <= syl[s2][1]){
                printf("%c", str[i]);
            }
            else{
                printf("+");
            }
        }
        printf("\n");
        //line 2
        for(int i = 0; i < len; i++){
            if(syl[s1][0] <= i && i <= syl[s1][1]
            || syl[s2][0] <= i && i <= syl[s2][1]){
                printf("+");
            }
            else{
                printf("%c", str[i]);
            }
        }
        printf("\n");
        //line 2


    }
}