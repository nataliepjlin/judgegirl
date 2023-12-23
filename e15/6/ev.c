#include "eval.h"
int eval(int exp[]) {
    /* add your code */
    int n = exp[0], prev = exp[1];
    int ret = 0;
    int add = 0, sub = 0, mul = 0, div = 0, muldiv = 0;
    for(int i = 2; i <= n; i++){
        if(i % 2 == 0){
            if(exp[i] == 1 || exp[i] == 2){
                ret -= (sub * (mul || div) * muldiv 
                    + sub * !(mul || div) * prev);
                ret += (!sub * (mul || div) * muldiv 
                    + !sub * !(mul || div) * prev);
                sub = 0, add = 0, mul = 0, div = 0, muldiv = 0;
                sub = (exp[i] == 2), add = (exp[i] == 1);
            }
            else if(exp[i] == 3 || exp[i] == 4){
                muldiv = (!mul && !div) * prev + muldiv * !(!mul && !div);
                mul = (exp[i] == 3), div = (exp[i] == 4);
            }
            else{
                return -2147483646;
            }
        }//operators
        else{
            if(mul)
                muldiv *= exp[i];
            else if(div){
                if(!exp[i]) return -2147483647;
                muldiv /= exp[i];
            }
            prev = exp[i];
        }
    }//for i
    ret -= (sub * (mul || div) * muldiv 
        + sub * !(mul || div) * prev);
    ret += (!sub * (mul || div) * muldiv 
        + !sub * !(mul || div) * prev);
    return ret;
}