#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 1000001
#define isOp(c) ((c == '+') || (c == '-') || (c == '*') || (c == '/'))

typedef struct{
    int valid;
    int val;
    int nextIdx;
}info;

info getNum(char str[], int s, int len){
    int n = 0;
    while(isdigit(str[s]) && s < len){
        n = n * 10 + (str[s] - '0');
        s++;
    }
    return (info){1, n, s};
}

info solve(int s, char str[], int len){
    info l, r;
    char op;
    if(str[s] == '('){
        s++;
        if(isdigit(str[s])){
            l = getNum(str, s, len);
            op = str[l.nextIdx];
            if(!isdigit(str[l.nextIdx + 1])) return (info){0, 0, 0};
            r = getNum(str, l.nextIdx + 1, len);
        }
        else if(str[s] == '('){
            l = solve(s, str, len);
            op = str[l.nextIdx];
            if(str[l.nextIdx + 1] != '(') return (info){0, 0, 0};
            r = solve(l.nextIdx + 1, str, len);
        }
    }
    else{
        return (info){0, 0, 0};
    }

    if(!l.valid || !isOp(op) || !r.valid || str[r.nextIdx] != ')')
        return (info){0, 0, 0};
    if(op == '+') return (info) {1, l.val + r.val, r.nextIdx + 1};//advances the position to the character after the closing parenthesis
    if(op == '-') return (info) {1, l.val - r.val, r.nextIdx + 1};
    if(op == '*') return (info) {1, l.val * r.val, r.nextIdx + 1};
    if(op == '/') return (info) {1, l.val / r.val, r.nextIdx + 1};
}
int main(){
    char str[SIZE];
    while(scanf("%s", str) == 1){
        int len = strlen(str);
        info s = solve(0, str, len);
        if(s.valid == 1 && s.nextIdx == len)
            printf("%d\n", s.val);
        else
            printf("invalid\n");
    }
    return 0;
}