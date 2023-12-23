#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 32
#define HASH 1000
// #define debug
int main(){
    char instr[SIZE];
    char hash[HASH][5][SIZE]; 
    int counts[HASH][5] = {{0}};
    int hashIdx[HASH] = {0};
    while(scanf("%s", instr) == 1){
        int len = strlen(instr), valid = 1, sum = 0;
        for(int l = 0; l < len && valid; l++){
            valid = ((isdigit(instr[l]) && l)
            || instr[l] == '_' || isalpha(instr[l]));
            sum += instr[l];
        }
        #ifdef debug
        printf("\ninstr = \"%s\", valid = %d\n", instr, valid);
        #endif
        if(valid){
            sum %= 1000; 
            #ifdef debug
            printf("hash sum = %d\n", sum);
            #endif
            int found = 0, i = 0;
            for(i; i < hashIdx[sum] && !found; i++){
                found = (strcmp(hash[sum][i], instr) == 0);
            }
            if(!found){
                strcpy(hash[sum][i], instr);
                hashIdx[sum] ++;
            }
            else{
                i --;
            }
            counts[sum][i] ++;
            printf("%s %d\n", instr, counts[sum][i]);
        }
    }
    return 0;
}