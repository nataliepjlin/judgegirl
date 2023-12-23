#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXS 1000
#define MAXN 10000
#define MAXCHAR 101
#define MAXCAP 1000
int f(char *str, int s){
    int hashVal = 0;
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        int isNum = (isdigit(str[i]) != 0);
        hashVal = (hashVal + ((str[i] - '0') * isNum + (str[i]) * !isNum)) % s;
    }
    return hashVal;
}
int main(){
    char inputs[MAXN][MAXCHAR];
    int hashT[MAXS][MAXCAP];
    int hashLen[MAXS] = {0};
    int size, n, q;//n inpus, q queries
    scanf("%d%d%d", &size, &n, &q);
    for(int i = 0; i < n; i++){
        scanf("%s", inputs[i]);
        int hashVal = f(inputs[i], MAXS);
        int same = 0;
        for(int j = 0; j < hashLen[hashVal] && !same; j++){
            same = (strcmp(inputs[i], inputs[hashT[hashVal][j]]) == 0);
        }
        if(!same){
            hashT[hashVal][hashLen[hashVal]] = i;
            hashLen[hashVal] ++;
        }
    }//build hashT
    char query[MAXCHAR];
    for(int i = 0; i < q; i++){
        scanf("%s", query);
        int hashVal = f(query, MAXS);
        int found = -1;
        for(int j = 0; j < hashLen[hashVal] && found == -1; j++){
            if(strcmp(query, inputs[hashT[hashVal][j]]) == 0){
                found = f(query, size);
            }
        }
        printf("%d\n", found);
    }
    return 0;
}