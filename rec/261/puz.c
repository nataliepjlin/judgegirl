#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 10
// #define debug
void collect(char uppers[], char *str, int *u){
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(isupper(str[i]) && strchr(uppers, str[i]) == NULL){
            uppers[*u] = str[i];
            *u += 1;
        }
    }
}
int getIdx(char uppers[], int u, char c){
    for(int i = 0; i < u; i++){
        if(uppers[i] == c)
            return i;
    }
    return -1;
}
int convert(int table[], char *s, char uppers[], int u){
    int len = strlen(s);
    int num = 0;
    for(int i = 0; i < len; i++){
        int isnum = (isdigit(s[i]) != 0);
        num = num * 10 + (s[i] - '0') * isnum + table[getIdx(uppers, u, s[i])] * !isnum;
    }
    return num;
}
void printNum(int n, char *s){
    int len = strlen(s);
    int test = n + (!n), digit = 0;
    while(test){
        digit ++;
        test /= 10;
    }
    #ifdef debug
    printf("digit = %d, vs len = %d\n", digit, len);
    #endif
    if(digit < len){
        for(int i = 0; i < len - digit; i++){
            printf("0");
        }
    }
    printf("%d", n);
}
int solve(int table[], int t, char s1[], char s2[], char s3[],
char uppers[], int u){
    if(t == u){
        int n1 = convert(table, s1, uppers, u);
        int n2 = convert(table, s2, uppers, u);
        int n3 = convert(table, s3, uppers, u);
        if(n1 * n2 == n3){
            printNum(n1, s1);
            printf(" x ");
            printNum(n2, s2);
            printf(" = ");
            printNum(n3, s3);
            printf("\n");
            exit(0);
        }
        return 0;
    }
    for(int i = 0; i < MAX; i++){
        table[t] = i;
        if(solve(table, t + 1, s1, s2, s3, uppers, u))
            return 1;
    }
    return 0;
}
int main(){
    char s1[MAX], s2[MAX], s3[MAX];
    scanf("%s%s%s", s1, s2, s3);
    char uppers[MAX * 3] = {0}; int u = 0;
    collect(uppers, s1, &u);
    collect(uppers, s2, &u);
    collect(uppers, s3, &u);
    int table[MAX * 3] = {0}, t = 0;
    solve(table, 0, s1, s2, s3, uppers, u);
}