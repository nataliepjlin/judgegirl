#include<stdio.h>
#include<string.h>
#define SIZE 1000
#define SUBSIZE 100
// #define debug
int main(){
    int idx = 0;
    int counts[SIZE][SUBSIZE] = {{0}};
    char hash[SIZE][SUBSIZE][4];
    int hashIdx[SIZE] = {0};
    char instr[SIZE];
    memset(hash, '\0', sizeof(hash));
    while(scanf("%s", instr) == 1){
        int len = strlen(instr);
        #ifdef debug
        printf("\ninstr = %s, len = %d\n", instr, len);
        #endif
        for(int i = 0; i + 3 <= len; i++){
            char instrCut[SIZE]; memset(instrCut, '\0', sizeof(instrCut));
            strncpy(instrCut, instr + i, 3);
            int sum = ((instrCut[0]+ instrCut[1]+ instrCut[2]) * 7 + 2222) % SIZE;
            #ifdef debug
            printf("sum = %d\n", sum);
            #endif
            instrCut[strlen(instrCut) + 1] = '\0';
            int j = 0, found = 0;
            for(j; j < hashIdx[sum] && !found; j++){
                found = (strcmp(hash[sum][j], instrCut) == 0);
            }
            j -= (found);
            hashIdx[sum] += (!found);
            strcpy(hash[sum][j], instrCut);
            counts[sum][j] ++;
            #ifdef debug
            printf("j = %d, found = %d, counts[sum][j] = %d\n", j, found, counts[sum][j]);
            #endif
        }
    }//while input
    int r1 = -1, r2 = -1, r3 = -1;
    int c1 = -1, c2 = -1, c3 = -1;
    for(int i = 0; i < SIZE; i++){
        if(!hashIdx[i]) continue;
        for(int j = 0; j < hashIdx[i]; j++){
            if(r1 == -1 || counts[r1][c1] < counts[i][j]
            || (counts[r1][c1] == counts[i][j] && strcmp(hash[r1][c1], hash[i][j]) > 0)){
                r3 = r2, c3 = c2;
                r2 = r1, c2 = c1;
                r1 = i, c1 = j;
            }
            else if(r2 == -1 || counts[r2][c2] < counts[i][j]
            || (counts[r2][c2] == counts[i][j] && strcmp(hash[r2][c2], hash[i][j]) > 0)){
                r3 = r2, c3 = c2;
                r2 = i, c2 = j;
            }
            else if(r3 == -1 || counts[r3][c3] < counts[i][j]
            || (counts[r3][c3] == counts[i][j] && strcmp(hash[r3][c3], hash[i][j]) > 0)){
                r3 = i, c3 = j;
            }
        }
    }
    printf("%s\n", hash[r1][c1]);
    printf("%s\n", hash[r2][c2]);
    printf("%s\n", hash[r3][c3]);
    return 0;
}