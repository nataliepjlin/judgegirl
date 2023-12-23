#include<stdio.h>
// #define DEBUG
int main(){
    int counts[26] = {0};
    char chr;
    while(scanf("%c", &chr) != EOF){
        #ifdef DEBUG
        printf("asc = %d\n", chr);
        #endif
        if(65 <= chr && chr <= 90) counts[(chr + 32) - 97] ++;
        else if(97 <= chr && chr <= 122) counts[chr - 97] ++;
    }
    for(int i = 0; i < 26; i++){
        printf("%d\n", counts[i]);
    }
    return 0;
}