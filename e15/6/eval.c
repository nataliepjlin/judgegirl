#include <stdio.h>
#include <string.h>
#include <assert.h>
// #define debug
int eval(int exp[]){
    int ret = 0;
    int n = exp[0], prev = exp[1];
    int toAdd = 0, toMinus = 0, MulDiv, toMul = 0, toDiv = 0;
    
    for(int i = 2; i <= n; i++){
        if(i % 2 == 0){
            if(exp[i] == 1 || exp[i] == 2){
                if(toMinus){
                    ret -= (toMul || toDiv) ? MulDiv : prev;
                    toMinus = 0;
                }
                else{
                    ret += (toMul || toDiv) ? MulDiv : prev;
                    toAdd = 0;
                }
                toMul = toDiv = 0;
                toAdd = (exp[i] == 1), toMinus = (exp[i] == 2);
            } 
            else if(exp[i] == 3 || exp[i] == 4){
                if(!toMul && !toDiv) MulDiv = prev;
                toMul = (exp[i] == 3), toDiv = (exp[i] == 4);
            }
            else{
                return -2147483646;
            }

        }//exp
        else if(toMul) MulDiv *= exp[i];
        else if(toDiv){
            if(!exp[i]){
                return -2147483647;
            }
            MulDiv /= exp[i];
        }
        prev = exp[i];
    }
    
    if(toAdd){
        ret += (toMul || toDiv) ? MulDiv : prev;
    } 
    else if(toMinus){
        ret -= (toMul || toDiv) ? MulDiv : prev;
    }
    #ifdef debug
    printf("final MulDiv = %d, ret = %d\n", MulDiv, ret);
    #endif
    return ret;
}
int main() {
    int exp[1024];
    memset(exp, -1, sizeof(exp));
    scanf("%d", &exp[0]);
    for (int i = 1; i <= exp[0]; i++)
        scanf("%d", &exp[i]);
    int ret = eval(exp);
    printf("%d\n", ret);
    return 0;
}