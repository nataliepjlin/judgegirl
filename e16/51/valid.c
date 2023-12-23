#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXN 30
#define SIZE 8
// #define debug
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void bs(int type[MAXN], int idx, char plate[MAXN][SIZE]){
    for(int i = 0; i < idx; i++){
        for(int j = 0; j < idx - i - 1; j++){
            if(strcmp(plate[type[j]], plate[type[j + 1]]) > 0){
                swap(&type[j], &type[j + 1]);
            }
        }
    }
}
int main(){
    char plate[MAXN][SIZE];
    int type1[MAXN], idx1 = 0;
    int type2[MAXN], idx2 = 0;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", plate[i]);
        int len = strlen(plate[i]);
        int valid = (len == 7 && strstr(plate[i], "44") == NULL 
        && (plate[i][2] == '-' || plate[i][3] == '-'));
        #ifdef debug
        printf("plate[%d] = %s, init valid = %d\n", i, plate[i], valid);
        #endif
        if(!valid) continue;

        int dashLoc = strchr(plate[i], '-') - plate[i];
        #ifdef debug
        printf("dashLoc = %d\n", dashLoc);
        #endif
        int sum = 0, hasDigit = 0;
        int charCount[128] = {0};
        for(int l = 0; l < len && valid; l++){
            valid = (valid && isalnum(plate[i][l]) != 0 || l == dashLoc);
            charCount[plate[i][l]] += valid;
            #ifdef debug
            printf("charCount[%c] = %d\n", plate[i][l], charCount[plate[i][l]]);
            #endif
            valid = (valid && charCount[plate[i][l]] <= 2);
            hasDigit += (isdigit(plate[i][l]) != 0);
            sum += (plate[i][l] - '0') * (isdigit(plate[i][l]) != 0);
        }
        valid = (valid && sum % 7 != 0 && hasDigit);
        #ifdef debug
        printf("sum = %d, hasDigit = %d, now valid = %d\n\n", sum, hasDigit, valid);
        #endif
        if(valid){
            if(plate[i][2] == '-'){
                type1[idx1] = i;
                idx1 ++;
            }
            else{
                type2[idx2] = i;
                idx2 ++;
            }
        }
    }
    bs(type1, idx1, plate);
    bs(type2, idx2, plate);
    for(int i = 0; i < idx1; i++){
        printf("%s\n", plate[type1[i]]);
    }
    for(int i = 0; i < idx2; i++){
        printf("%s\n", plate[type2[i]]);
    }
    return 0;
}