#include<stdio.h>
int main(){
    int k;
    int n, remain = 0, val = -1;
    scanf("%d", &k);

    //1st
    scanf("%d", &n);
    val = (10 * remain + n) / k;
    remain = (10 * remain + n) % k;
    if(val == 0 && scanf("%d", &n) != EOF){
        val = (10 * remain + n) / k;
        printf("%d\n", val);
        remain = (10 * remain + n) % k;
    }
    else{
        printf("%d\n", val);
    }
    //
    while(scanf("%d", &n) != EOF){
        val = (10 * remain + n) / k;
        printf("%d\n", val);
        remain = (10 * remain + n) % k;
    }
    
    return 0;
}