#include<stdio.h>
#include<string.h>
#include<ctype.h>
// #define debug
typedef struct{
    int val;
    int valid;
    int next;
}info;
info getnum(char *string, int s, int len){
    int val = 0;
    while(isdigit(string[s]) && s < len){
        val = val * 10 + (string[s] - '0');
        s++;
    }
    #ifdef debug
    printf("val = %d\n", val);
    #endif
    return (info){val, 1, s};
}
info expressionEval(char *string, int len, int s){
    #ifdef debug
    printf("s = %d\n", s);
    #endif
    if(s >= len)
        return (info){-2147483648, 0, 0};
    else if(string[s] == '-'){
        info ret = (expressionEval(string, len, s + 1));
        if(!ret.valid)
            return (info){-2147483648, 0, 0};
        return (info){-ret.val, ret.valid, ret.next};
    }
    else if(isdigit(string[s]))
        return (getnum(string, s, len));
    else if(string[s] == '('){
        info l, r; char op;
        s++;
        l = expressionEval(string, len, s);
        #ifdef debug
        printf("left val = %d\n", l.val);
        #endif
        if(!l.valid)
            return (info){-2147483648, 0, 0};
        op = string[l.next];
        #ifdef debug
        printf("op = %c\n", op);
        #endif
        if(!(op == '+' || op == '-' || op == '*' || op == '/'))
            return (info){-2147483648, 0, 0};
        r = expressionEval(string, len, l.next + 1);
        if(!r.valid || string[r.next] != ')')
            return (info){-2147483648, 0, 0};
        #ifdef debug
        printf("%d %c %d\n", l.val, op, r.val);
        #endif
        if(op == '+') return (info){l.val + r.val, 1, r.next + 1};
        else if(op == '-') return (info){l.val - r.val, 1, r.next + 1};
        else if(op == '/'){
            if(r.val == 0)
                return (info){-2147483648, 0, 0};
            return (info){l.val / r.val, 1, r.next + 1};
        }
        else if(op == '*') return (info){l.val * r.val, 1, r.next + 1};
    }
    return (info){-2147483648, 0, 0};
}
int expression(char *string){
    int len = strlen(string);
    #ifdef debug
    printf("len = %d\n", len);
    #endif
    info ans = expressionEval(string, len, 0);
    return (ans.valid && ans.next == len) ? ans.val : (-2147483648);
}