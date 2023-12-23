#include<stdio.h>
#include<string.h>
#define MAX 1000
#define R 1001
#define ALP 26
#define debug
void getWordList(char word[], int list[], int len){
    for(int i = 0; i < len; i++){
        list[word[i] - 'a'] ++;
    }
}
void perm(int list[], int idx, int len, char toPrint[], int rules[ALP][ALP]){
    if(idx == len){
        printf("%s\n", toPrint);
        return;
    }
    for(int i = 0; i < ALP; i++){
        if(list[i] <= 0 
        || (idx != 0 && rules[toPrint[idx - 1] - 'a'][i] == 1))
                continue;
        list[i] --;
        toPrint[idx] = 'a' + i;
        perm(list, idx + 1, len, toPrint, rules);
        toPrint[idx] = 0;
        list[i] ++;
    }
}
int main(){
    char word[MAX];
    scanf("%s", word);
    int len = strlen(word);
    int list[ALP] = {0};
    getWordList(word, list, len);

    int n; 
    scanf("%d", &n);
    int rules[ALP][ALP] = {{0}};
    char tmp[3];
    for(int i = 0; i < n; i++){
        scanf("%s", tmp);
        rules[tmp[0] - 'a'][tmp[1] - 'a'] = 1;
    } 
    char toPrint[MAX] = {0};
    perm(list, 0, len, toPrint, rules);
}