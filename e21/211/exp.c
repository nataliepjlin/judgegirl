#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 1000000
#define debug
int add(int a, int b){
    return a + b;
}
int sub(int a, int b){
    return a - b;
}
int mul(int a, int b){
    return a * b;
}
int div(int a, int b){
    return a / b;
}
int main(){
    char eq[MAX];
    int (*operators[4])(int, int) = {&add, &sub, &mul, &div};
    while(scanf("%s", eq) == 1){
        int l = 0, r = 0;
        int len = strlen(eq);
        int n1 = 0, n2 = 0;
        int out = 0;
        char op = 0;
        int hasOp = 0;
        char lastOp = '+';
        int valid = 1;
        for(int i = 0; i < len && !(l < r) && valid; i++){
            if(eq[i] == '(' || eq[i] == ')'){
                l += (eq[i] == '('), r += (eq[i] == ')');
                if(!(l < r) && (eq[i] == ')') && n1 && op && n2){
                    #ifdef debug
                    printf("%d %c (%d %c %d) = ", out, lastOp, n1, op, n2);
                    #endif
                    out = operators[(lastOp == '-') * 1 + (lastOp == '*') * 2 + (lastOp == '/') * 3]
                    (out, operators[(op == '-') * 1 + (op == '*') * 2 + (op == '/') * 3](n1, n2));
                    #ifdef debug
                    printf("%d\n", out);
                    #endif
                    n1 = 0, n2 = 0, op = 0;
                }
            }//()
            else if(isdigit(eq[i])){
                if(!op){
                    if(!n1){
                        valid = (eq[i - 1] == '(');
                    }
                    n1 = n1 * 10 + eq[i] - '0';
                }
                else{
                    n2 = n2 * 10 + eq[i] - '0';
                }
            }//num
            else{
                if(eq[i - 1] == ')')
                    lastOp = eq[i];
                else{
                    op = eq[i];
                    hasOp = 1;
                }
            }//op
        }//for
        if(l != r || !l || !hasOp || !valid){
            printf("invalid\n");
        }
        else{
            printf("%d\n", out);
        }
    }//while
}